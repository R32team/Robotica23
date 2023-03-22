from helpers.config_helper import Config
from helpers.logging_helper import logger
from helpers.web_browser_helper import WebBrowser

import socket
from threading import Thread
from typing import Callable


class SocketClient:
    def __init__(self, connection, ip, port, on_message):
        self.ip = ip
        self.connection = connection
        self.port = port
        self.on_message = on_message

    def run(self):
        while True:
            message = self.connection.recv(1024).decode("utf-8")
            message.strip()

            if message:
                logger.info(f'Received message from {self.ip}: {message}')

                self.on_message(message)


class SocketServer:
    ip: str
    port: int

    ''' Possible codes:
    * -1: NAO is moving
    *  0: NAO is in home base 
    * 1-10: Number of painting described 
    '''
    status: int

    clients = []

    s: socket.socket

    def __init__(self, config: Config):
        self.ip = config.socket_ip
        self.port = config.socket_port

        self.start_server()

    def start_server(self):
        self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

        self.s.bind((self.ip, self.port))
        self.s.listen(1)

        logger.info(f'Socket server started')

        try:
            while True:
                # Establish connection with client.
                conn, (ip, port) = self.s.accept()

                Thread(target=self.on_new_client, args=(
                    conn, ip, port), daemon=True).start()
        except Exception as e:
            logger.info(str(e))

            self.s.close()

    def send_to_all_clients(self, msg):
        for client in self.clients:
            client.connection.sendall(msg.encode())

    def on_new_client(self, conn, ip, port):
        client = SocketClient(conn, ip, port, self.on_received_message)

        self.clients.append(conn)

        try:
            client.run()
        except Exception as e:
            logger.error(str(e))

            client.connection.close()

        self.clients.remove(client)

    def on_received_message(self, message):
        self.send_to_all_clients(message)
        manage_message(message)


def manage_message(message):
    global socket_status

    source, body, destination = message.split('_')

    if (source == 'app' and destination == 'arduino' and body in [str(i) for i in range(1, 11)]):
        socket_status = -1
    elif (source == 'arduino' and destination == 'nao' and body in [str(i) for i in range(1, 11)]):
        socket_status = int(body)
        WebBrowser.open_window(body)
    elif (source == 'nao' and destination == 'arduino'):
        socket_status = -1
        WebBrowser.close_window()
    elif (source == 'arduino' and destination == 'app'):
        socket_status = 0
