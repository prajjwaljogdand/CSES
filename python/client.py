import time, socket, sys, threading

def send_msg():
    while True:
        
        message = input()
        socket_server.send(message.encode())

def recv_msg():
    while True:
        received = socket_server.recv(1024)
        received = received.decode()
        print(server_name,":",received)
 
socket_server = socket.socket()
server_host = socket.gethostname()
ip = socket.gethostbyname(server_host)
sport = 5050
 
print('This is your IP address: ',ip)
server_host = input('Enter friend\'s IP address:')
name = input('Enter Friend\'s name: ')
 
 
socket_server.connect((server_host, sport))
 
socket_server.send(name.encode())
server_name = socket_server.recv(1024)
server_name = server_name.decode()
 
print(server_name,' has joined...')
'''while True:
    message = (socket_server.recv(1024)).decode()
    print(server_name, ":", message)
    message = input("Me : ")
    socket_server.send(message.encode())'''

t1 = threading.Thread(target=send_msg)
t1.start()
recv_msg()