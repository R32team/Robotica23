from helpers.config_helper import Config
from helpers.socket_server_helper import SocketServer
from helpers.logging_helper import logger

import utilities

if __name__ == '__main__':
    utilities.get_file_path('3')

    config_helper = Config()
    socket_helper = SocketServer(config_helper)
