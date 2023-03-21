from helpers.config_helper import Config
from helpers.socket_server_helper import SocketServer
from helpers.logging_helper import logger

import helpers.socket_server_helper as server_helper

import utilities
import time

from flask import Flask, jsonify, render_template


app = Flask(__name__)

# Web App calls


@app.route('/')
def index():
    status = server_helper.socket_status

    return render_template('index.html', status_code=status)

# Api calls


@app.route('/api/info', methods=['GET'])
def info():
    return jsonify({'code': 200, 'status': 'online', 'elapsed time': utilities.getElapsedTime(startTime)}), 200


if __name__ == '__main__':
    config_helper = Config()
    socket_helper = SocketServer(config_helper)

    startTime = time.time()

    app.run(host=config_helper.srv_host, port=config_helper.srv_port,
            debug=config_helper.srv_debug)
