from threading import Thread
from helpers.config_helper import Config
from helpers.logging_helper import logger

import utilities
import time

import pandas as pd
from sklearn.tree import DecisionTreeClassifier
import numpy as np

from flask import Flask, request, jsonify

app = Flask(__name__)
decisioni = []

@app.route('/api/info', methods=['GET'])
def info():
    return jsonify({'code': 200, 'status': 'online', 'elapsed time': utilities.getElapsedTime(startTime)}), 200

@app.route('/api/<string:Input>', methods=['POST'])
def recording_input(Input):
    if Input != '' and Input != None:
        try:
            decisioni.append(int(Input))
            result = ""
            if len(decisioni) == 5:
                # load the data for the museum exhibits
                data = pd.read_csv('data.csv')

                # train a decision tree classifier on the data
                X = data.drop(columns=['Quadro', 'Canto', 'Dove', 'Tono', 'Emozioni'])
                y = data['Quadro']

                clf = DecisionTreeClassifier()
                clf.fit(X, y)

                # predict the exhibit route based on the answers
                ans   = np.array(decisioni)
                ans   = ans.reshape(-1,1)
                route = clf.predict(ans)
                route = list(route)
                visited = set()
                route[:] = [x for x in route if x not in visited and not visited.add(x)]

                i = 1
                for idx in route:
                    result += "L'opera numero " + str(i) + "che puoi visitare è: " + str(idx) + " "
                    i +=1


            json = {'code': 200, 'message': 'OK', 'result': result}

            return jsonify(json), 200
        except Exception as e:
            logger.error(str(e))
            return jsonify({'code': 500, 'message': str(e)}), 500
    else:
        logger.error('No input was specified')
        return jsonify({'code': 500, 'message': 'Input is invalid'}), 500


def init_server():
    app.run(host=config_helper.srv_host, port=config_helper.srv_port, debug=config_helper.srv_debug)


if __name__ == '__main__':
    config_helper = Config()
    startTime = time.time()
    init_server()
