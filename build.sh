#!/bin/bash

gcc -o exploit exploit.c utils.c msg_spray.c
gcc -o my_shell my_shell.c
gcc -o get_root get_root.c
