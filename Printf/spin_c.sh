# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    spin_c.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/18 05:00:19 by fvoicu            #+#    #+#              #
#    Updated: 2023/10/18 05:00:28 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

spin() {
	printf "\033[38;5;6m"
    local spin="/-\|"
    while :; do
        for i in $(seq 0 3); do
            printf "\r  ${spin:$i:1} Cleaning..."
            sleep 0.1
        done
    done
}

spin &
spin_pid=$!
sleep 1
kill $spin_pid 2>/dev/null

printf	"\033[0m"