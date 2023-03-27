# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 21:22:22 by asoursou          #+#    #+#              #
#    Updated: 2023/03/27 07:53:39 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CFLAGS	:= -Wall -Wextra -Werror -MMD -MP
NAME	:= libft.a
SRC		:= ft_atoi \
	ft_bound_size_t \
	ft_bzero \
	ft_calloc \
	ft_isalnum \
	ft_isalpha \
	ft_isascii \
	ft_isdigit \
	ft_islower \
	ft_isprint \
	ft_isspace \
	ft_isupper \
	ft_itoa \
	ft_lstadd_back_bonus \
	ft_lstadd_front_bonus \
	ft_lstclear_bonus \
	ft_lstdelone_bonus \
	ft_lstiter_bonus \
	ft_lstlast_bonus \
	ft_lstmap_bonus \
	ft_lstnew_bonus \
	ft_lstsize_bonus \
	ft_memchr \
	ft_memcmp \
	ft_memcpy \
	ft_memdup \
	ft_memdup_fill \
	ft_memmove \
	ft_memset \
	ft_putchar_fd \
	ft_putendl_fd \
	ft_putnbr_fd \
	ft_putstr_fd \
	ft_split \
	ft_strchr \
	ft_strchrnul \
	ft_strdup \
	ft_striteri \
	ft_strjoin \
	ft_strlcat \
	ft_strlcpy \
	ft_strlen \
	ft_strmapi \
	ft_strncmp \
	ft_strnlen \
	ft_strnstr \
	ft_strrchr \
	ft_strtrim \
	ft_substr \
	ft_tolower \
	ft_toupper
SRC		:= $(addsuffix .c, $(SRC))
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
