import helpers.config_helper as config_helper
from helpers.logging_helper import logger
import utilities

import socket

import queue

import threading

socket_status = 0


class SocketServer:
    ip: str
    port: int

    ''' Possible codes:
    * -1: NAO is moving
    *  0: NAO is in home base 
    * 1-10: Number of painting described 
    '''
    status: int

    s: socket.socket

    def __init__(self, config: config_helper.Config):
        self.ip = config.socket_ip
        self.port = config.socket_port

        threading.Thread(target=self.start_server, daemon=True).start()

    def start_server(self):
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        self.s.bind((self.ip, self.port))
        self.s.listen(1)

        logger.info(f'Socket server started')

        conn, _ = self.s.accept()

        while True:
            message = conn.recv(1024).decode("utf-8")
            message.strip()
            if message:
                logger.info(f'Received message: {message}')
                manage_message(message)


def manage_message(message):
    global socket_status

    source, body, destination = message.split('_')

    if (source == 'app' and destination == 'arduino' and body in [str(i) for i in range(1, 11)]):
        socket_status = -1
    elif (source == 'arduino' and destination == 'nao' and body in [str(i) for i in range(1, 11)]):
        socket_status = int(body)
    elif (source == 'nao' and destination == 'arduino'):
        socket_status = -1
    elif (source == 'arduino' and destination == 'app'):
        socket_status = 0
