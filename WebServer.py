#This is a web server that handles one HTTP request at a time. It accepts and parses the HTTP request,
#gets the requested line from the server's file system, creates an HTTP response consisting of the requested
#file preceded by header lines, and sends the response directly to the client

# import socket module
from socket import *
# In order to terminate the program
import sys


def webServer(port=13331):
  serverSocket = socket(AF_INET, SOCK_STREAM)
  #Prepare a server socket
  serverSocket.bind(("", port)) #associates the server port number with this socket
  serverSocket.listen(1) #listen for a client to come through

  HTTP_200 = 'HTTP/1.1 200 OK\r\n'
  HTTP_404 = 'HTTP/1.1 404 Not Found\r\n'
  
  while True:
    #Establish the connection
    connectionSocket, addr = serverSocket.accept() #the server listens for TCP connections from the client
    try:

      try:
        message = connectionSocket.recv(1024)
        filename = message.split()[1]
        f = open(filename[1:])
        outputdata = f.read()
        
        #Send one HTTP header line into socket.
        connectionSocket.send(HTTP_200.encode())

        #Send the content of the requested file to the client
        for i in range(0, len(outputdata)):
          connectionSocket.send(outputdata[i].encode())

        connectionSocket.send("\r\n".encode())
        connectionSocket.close()
      except IOError:
        # Send response message for file not found (404)
          connectionSocket.send(HTTP_404.encode()) 

        #Close client socket
          connectionSocket.close()
          sys.exit()
         
    except (ConnectionResetError, BrokenPipeError):
      pass

  serverSocket.close()
  sys.exit()  # Terminate the program after sending the corresponding data

if __name__ == "__main__":
  webServer(13331)
