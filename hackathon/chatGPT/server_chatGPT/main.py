from threading import Thread
from helpers.config_helper import Config
from helpers.logging_helper import logger
from helpers.speech_recognition_helper import SpeechRecognition

import utilities
import time

from flask import Flask, request, jsonify

app = Flask(__name__)
solar_edge = None

@app.route('/api/info', methods=['GET'])
def info():
    return jsonify({'code': 200, 'status': 'online', 'elapsed time': utilities.getElapsedTime(startTime)}), 200

@app.route('/api/input/<string:Input>', methods=['POST'])
def recording_input(Input):
    if Input != '' and Input != None and Input in utilities.inputs:
        try:
            uploaded_file = None
            if (Input not in utilities.inputs_without_file):
                uploaded_file = request.files['file']

            if (Input in utilities.inputs_without_file or (uploaded_file and uploaded_file.filename != '')):
                if ((uploaded_file and uploaded_file.filename != '')):
                    path = f'recordings/recording.wav'
                    uploaded_file.save(path)
                    speech_recognition = SpeechRecognition(path)

                    solar_edge.input(Input, speech_recognition.result)

                    return jsonify({'code': 200, 'message': 'OK', 'result': speech_recognition.result}), 200

                result = solar_edge.input(Input, '')

                json = {'code': 200, 'message': 'OK'}

                if (result != None and result != []):
                    json['result'] = {
                        'self_usage': result[0],
                        'self_usage_batteries': result[1],
                        'total_capacity': result[2],
                        'total_power': result[3]
                    }

                return jsonify(json), 200
            else:
                logger.error('No file passed')
                return jsonify({'code': 500, 'message': 'No file was passed'}), 500
        except Exception as e:
            logger.error(str(e))
            return jsonify({'code': 500, 'message': str(e)}), 500
    else:
        logger.error('No input was specified')
        return jsonify({'code': 500, 'message': 'Input is invalid'}), 500

@app.route('/api/recognise', methods=['POST'])
def recording():
    try:
        uploaded_file = request.files['file']

        if (uploaded_file and uploaded_file.filename != ''):
            path = f'recordings/recording.wav'
            uploaded_file.save(path)
            speech_recognition = SpeechRecognition(path)

            #chatGPT
            import openai

            openai.api_key = ""
            response = openai.ChatCompletion.create(
                model="gpt-3.5-turbo",
                messages=[
                        {"role": "user", "content": speech_recognition.result},
                    ]
            )

            result = ''
            for choice in response.choices:
                result += choice.message.content

            return jsonify({'code': 200, 'message': 'OK', 'result': result}), 200
        else:
            logger.error('No file passed')
            return jsonify({'code': 500, 'message': 'No file was passed'}), 500
    except Exception as e:
        logger.error(str(e))
        return jsonify({'code': 500, 'message': str(e)}), 500


def init_server():
    app.run(host=config_helper.srv_host, port=config_helper.srv_port, debug=config_helper.srv_debug)


if __name__ == '__main__':
    config_helper = Config()
    startTime = time.time()
    init_server()
