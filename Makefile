# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/30 20:20:12 by fvoicu            #+#    #+#              #
#    Updated: 2023/10/31 13:24:22 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:= lib.a

LIBFT_LIB	:= Libft/libft.a
PRINTF_LIB	:= Printf/libftprintf.a
LIBS		:= $(LIBFT_LIB) $(PRINTF_LIB)

INCS		:= Libft/libft.h  Printf/include/ft_printf.h

OBJS		:= $(SRCS:%.c=%.o)

all: $(NAME)

$(NAME): $(OBJS)
	@./progressbar.sh
	@printf "\n"
	@./spin.sh
	@make -C Libft --no-print-directory
	@make -C Printf --no-print-directory
	@ar -x $(LIBFT_LIB)
	@ar -x $(PRINTF_LIB)
	@ar -rcs $(NAME) *.o
	@rm -f *.o
	@./progressbar.sh

clean:
	@./progressbar.sh
	@printf "\n"
	@./spin_c.sh
	@make clean -C Libft --no-print-directory
	@make clean -C Printf --no-print-directory
	@./progressbar.sh
	
fclean: clean
	@make fclean -C Libft --no-print-directory	
	@make fclean -C Printf --no-print-directory
	@rm -f $(NAME)
	@./progressbar.sh

re: fclean all

.PHONY: all clean fclean re
