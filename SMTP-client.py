# assignment details: https://github.com/NYUCyberFellows-CSGY6843/assignment3-smtpclient

from socket import *

def smtp_client (port=1025, mailserver='127.0.0.1'):
    msg = "\r\n My message\r\n"
    endmsg = "\r\n.\r\n"
   
    # Create socket called clientSocket and establish a TCP connection with mailserver and port
    clientSocket = socket(AF_INET, SOCK_STREAM)
    clientSocket.connect((mailserver,port))

    recv = clientSocket.recv(1024).decode()
    #print(recv) #You can use these print statement to validate return codes from the server.

    # Send HELO command and print server response.
    heloCommand = 'HELO Alice\r\n'
    clientSocket.send(heloCommand.encode())
    recv1 = clientSocket.recv(1024).decode()

    # Send MAIL FROM command and handle server response.
    mailCommand = 'MAIL FROM: <lu2014@nyu.edu> \r\n'
    clientSocket.send(mailCommand.encode())
    rcv2 = clientSocket.recv(1024).decode()

    # Send RCPT TO command and handle server response.
    RCPTCommand = 'RCPT TO: <urena198@gmail.com>\r\n'
    clientSocket.send(RCPTCommand.encode())
    rcv3 = clientSocket.recv(1024).decode()
    
    # Send DATA command and handle server response.
    DataCommand = 'DATA\r\n'
    clientSocket.send(DataCommand.encode())
    rcv4 = clientSocket.recv(1024).decode()

    # Send message data.
    clientSocket.send(msg.encode())

    # Message ends with a single period, send message end and handle server response.
    clientSocket.send(endmsg.encode())
    rcv1 = clientSocket.recv(1024).decode()

    # Send QUIT command and handle server response.
    quitCommand = 'QUIT\r\n'
    clientSocket.send(quitCommand.encode())
    rcv1 = clientSocket.recv(1024).decode()
    clientSocket.close()

if __name__ == '__main__':
    smtp_client(1025, '127.0.0.1')
