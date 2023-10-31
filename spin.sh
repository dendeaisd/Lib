#!/bin/bash

spin() {
	printf "\033[38;5;6m"
    local spin="/-\|"
    while :; do
        for i in $(seq 0 3); do
            printf "\r  ${spin:$i:1} Compiling..."
            sleep 0.1
        done
    done
}

spin &
spin_pid=$!
sleep 1
kill $spin_pid 2>/dev/null

printf	"\033[0m"	