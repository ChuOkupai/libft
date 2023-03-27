# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 21:22:22 by asoursou          #+#    #+#              #
#    Updated: 2023/03/27 07:04:01 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
NAME	:= libft.a
SRC		:= $(wildcard *.c)
DEP		:= $(SRC:.c=.d)
OBJ		:= $(SRC:.c=.o)

$(NAME): $(OBJ)
	ar -rcs $@ $^

all: $(NAME)

bonus: all

clean:
	rm -f $(DEP) $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re

-include $(DEP)
