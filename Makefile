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

OBJS		=  ${SRCS:.c=.o}

HEADERS		= libft.h

NAME		= libft.a

CFLAGS		= -Wall -Wextra -Werror

all:		${NAME}

${NAME}:	${OBJS} ${HEADERS}
			ar -rcs $@ ${OBJS}

.c.o:		${HEADERS}
			gcc ${CFLAGS} -c $< -o ${<:.c=.o}

clean:
			rm -f ${OBJS}

fclean:		clean
			rm -f ${NAME}

re:			fclean all

.PHONY:		all clean fclean re
