# File to test socket
import socket

IP = 'localhost'
PORT = 5050

if __name__ == '__main__':
    message = input("Inserisci il messaggio da inviare: ")

    s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)

    s.connect((IP, PORT))

    s.send(message.encode())
