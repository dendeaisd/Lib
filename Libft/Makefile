# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fvoicu <fvoicu@student.42heilbronn.de>     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/10/15 13:57:02 by fvoicu            #+#    #+#              #
#    Updated: 2023/10/30 20:01:51 by fvoicu           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	:= libft.a
FLAGS 	:= -Wall -Wextra -Werror
RM 		:= rm -f
SRC 	:= \
	ft_isalpha.c ft_isdigit.c ft_isalnum.c ft_isascii.c ft_isprint.c \
	ft_strlen.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
	ft_strlcpy.c ft_strlcat.c ft_toupper.c ft_tolower.c ft_strchr.c \
	ft_strrchr.c ft_strncmp.c ft_memchr.c ft_memcmp.c ft_strnstr.c ft_atoi.c \
	ft_calloc.c ft_strdup.c ft_substr.c ft_strjoin.c ft_strtrim.c ft_split.c \
	ft_itoa.c ft_strmapi.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
	ft_putnbr_fd.c 	ft_striteri.c fv_strjoin_and_free.c	fv_strtok.c \
	get_next_line.c
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
	@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)Objects removed successfully🧽$(RESET)\n"

fclean:	clean
	@$(RM) $(NAME)
	@printf "$(UP)$(BEGIN)$(CUT)$(MAGENTA)Objects and library removed successfully🚽✨$(RESET)\n"

bonus: $(BOBJ)
	@ar rcs $(NAME) $^
	@printf "$(UP)$(BEGIN)$(CUT)$(GREEN)Libft bonus compiled successfully✅$(RESET)\n"
	
re:	fclean all

.PHONY: all clean fclean re