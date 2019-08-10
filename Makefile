SRCS		= ft_atoi_base.c \
			  ft_atoi.c \
			  ft_print_memory.c \
			  ft_putchar.c \
			  ft_putnbr_base.c \
			  ft_putnbr.c \
			  ft_putstr.c \
			  ft_putstr_non_printable.c \
			  ft_sort_int_tab.c \
			  ft_split.c \
			  ft_strcat.c \
			  ft_strcmp.c \
			  ft_strdup.c \
			  ft_strcpy.c \
			  ft_strjoin.c \
			  ft_strlcat.c \
			  ft_strlcpy.c \
			  ft_strlen.c \
			  ft_strncat.c \
			  ft_strncmp.c \
			  ft_strncpy.c \
			  ft_strstr.c

DEPS		= ${SRCS:.c=.d}

OBJS		=  ${SRCS:.c=.o}

HEADERS		= libft.h

NAME		= libft.a

CC			= gcc

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS}
			@echo 'create $@'
			@ar -rcs $@ ${OBJS}

%.o:		%.c
			@echo '${CC} $@'
			@${CC} ${CFLAGS} -MMD -c $< -o $@

clean:
			@echo 'remove objects and dependencies'
			@rm -f ${DEPS} ${OBJS}

fclean:		clean
			@echo 'remove ${NAME}'
			@rm -f ${NAME}

re:			fclean all

-include	${DEPS}

.PHONY:		all clean fclean re
