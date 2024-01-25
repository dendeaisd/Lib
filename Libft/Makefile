# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 13:57:02 by fvoicu            #+#    #+#              #
#    Updated: 2024/01/25 17:41:20 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= libft.a
FLAGS 	:= -Wall -Wextra -Werror
RM 		:= rm -f
SRC 	:= $(wildcard *.c)
BSRC 	:= \
	ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c \
	ft_lstiter.c ft_lstlast.c ft_lstmap.c ft_lstnew.c ft_lstsize.c

OBJ 	:= $(SRC:.c=.o)
BOBJ 	:= $(BSRC:.c=.o)


# Colors
CYAN		:= \033[38;5;6m
GREEN		:= \033[0;32m
YELLOW 		:= \033[93m
MAGENTA		:= \033[0;95m
RESET		:= \033[0m

#Cursor manipulation
UP		:= \033[A
CUT		:= \033[K
BEGIN	:= \033[0G


all:	$(NAME)

$(NAME): $(OBJ)
	@ar rcs $@ $^

%.o: %.c
	@printf "$(UP)$(BEGIN)$(CUT)$(CYAN)Compiling:$<...$(RESET)\n"
	@cc -c $(FLAGS) $< -o $@ 
	@printf "$(UP)$(BEGIN)$(CUT)$(GREEN)Libft compiled successfully✅$(RESET)\n"

clean:
	@for obj in $(OBJ) $(BOBJ); do \
		if [ -f $$obj ]; then \
			$(RM) $$obj; \
			printf "$(UP)$(CUT)$(YELLOW)Removing: $$obj...$(RESET)\n"; \
			sleep 0.03; \
		fi; \
	done
	@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)Objects removed successfully🧽$(RESET)"

fclean:	clean
	@$(RM) $(NAME)
	@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)Objects and library removed successfully🚽✨$(RESET)\n"

bonus: $(BOBJ)
	@ar rcs $(NAME) $^
	@printf "$(UP)$(BEGIN)$(CUT)$(GREEN)Libft bonus compiled successfully✅$(RESET)\n"
	
re:	fclean all

.PHONY: all clean fclean re