# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 10:01:49 by fvoicu            #+#    #+#              #
#    Updated: 2023/10/30 19:23:56 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a
NAME_2		:=	Printf
SHELL		:=	bash

CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -I./include -g

HEADER		:=	$(wildcard include/*.h)
SRC 		:=	$(wildcard ./src/*.c)
OBJ_DIR 	:=	obj
OBJ_FILES	:= $(notdir $(SRC:.c=.o))
OBJ			:= $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))


GREEN = \033[0;32m
MAGENTA = \033[0;95m

RESET = \033[0m
UP := "\033[A"

all: $(NAME) 
	
$(NAME): $(OBJ_DIR) $(OBJ)
	@./spin.sh
	@ar rcs $(NAME) $(OBJ)
	@echo -e -n "\r\033[K\c"
	@echo -e " $(GREEN)$(NAME_2) is Rrready!✅$(RESET)"
	@./progressbar.sh
	
$(OBJ_DIR): 
	@mkdir -p $(OBJ_DIR)
	@./progressbar.sh
$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@./progressbar.sh
	@rm -rf $(OBJ_DIR)
	@./spin_c.sh
	@echo -e -n "\r\033[K\c"
	@echo -e " $(MAGENTA)$(NAME_2) is Clean!🧽"
	@./progressbar.sh
	
fclean:
	@./progressbar.sh
	@rm -rf $(OBJ_DIR)
	@rm -f $(NAME)
	@./spin_c.sh
	@echo -e -n "\r\033[K\c"
	@echo -e "$(MAGENTA)$(NAME_2) is Super Clean!🚽✨"
	@./progressbar.sh
	
bonus: all

re: fclean all



.PHONY: all bonus clean fclean re