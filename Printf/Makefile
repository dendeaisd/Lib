# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/13 10:01:49 by fvoicu            #+#    #+#              #
#    Updated: 2023/10/31 12:32:45 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		:=	libftprintf.a
CC			:=	cc
CFLAGS		:=	-Wall -Wextra -Werror -I./include -g

HEADER		:=	$(wildcard include/*.h)
SRC 		:=	$(wildcard ./src/*.c)
OBJ_DIR 	:=	obj
OBJ_FILES	:= $(notdir $(SRC:.c=.o))
OBJ			:= $(addprefix $(OBJ_DIR)/, $(OBJ_FILES))


GREEN		:= \033[0;32m
MAGENTA		:= \033[0;95m
RESET		:= \033[0m

UP			:= \033[A
CUT			:= \033[K
BEGIN		:= \033[0G

all: $(NAME) 
	
$(NAME): $(OBJ_DIR) $(OBJ)
	@ar rcs $(NAME) $(OBJ)
	@printf "$(GREEN)Printf is Rrready!✅$(RESET)\n"
	
$(OBJ_DIR): 
	@mkdir -p $(OBJ_DIR)

$(OBJ_DIR)/%.o: src/%.c $(HEADER)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)
	@printf "$(MAGENTA)Printf is Clean!🧽$(RESET)\n"

fclean: clean
	@rm -f $(NAME)
	@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)Printf is Super Clean!🚽✨$(RESET)\n"

	
bonus: all

re: fclean all

.PHONY: all bonus clean fclean re