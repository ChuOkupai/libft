# DIRECTORIES
DEP_DIR	= dep
OBJ_DIR	= obj
DIR		= $(DEP_DIR) $(OBJ_DIR)

# FILES
NAME	= libft.a
SRC		= ft_atoi.c \
		  ft_atoi_base.c \
		  ft_bzero.c \
		  ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isblank.c \
		  ft_iscntrl.c \
		  ft_isdigit.c \
		  ft_isgraph.c \
		  ft_islower.c \
		  ft_isprint.c \
		  ft_ispunct.c \
		  ft_issign.c \
		  ft_isspace.c \
		  ft_isupper.c \
		  ft_isxdigit.c \
		  ft_itoa.c \
		  ft_itoa_base.c \
		  ft_lstadd.c \
		  ft_lstdel.c \
		  ft_lstdelone.c \
		  ft_lstfind.c \
		  ft_lstinsert.c \
		  ft_lstiter.c \
		  ft_lstmap.c \
		  ft_lstnew.c \
		  ft_lstrev.c \
		  ft_lstsize.c \
		  ft_lstsort.c \
		  ft_memalloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memprint.c \
		  ft_memset.c \
		  ft_memswap.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_base.c \
		  ft_putnbr_base_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c \
		  ft_qsort.c \
		  ft_str_is_alpha.c \
		  ft_str_is_lowercase.c \
		  ft_str_is_numeric.c \
		  ft_str_is_printable.c \
		  ft_str_is_uppercase.c \
		  ft_strcapitalize.c \
		  ft_strcat.c \
		  ft_strchr.c \
		  ft_strclr.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdel.c \
		  ft_strdup.c \
		  ft_strequ.c \
		  ft_striter.c \
		  ft_striteri.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strmap.c \
		  ft_strmapi.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strnequ.c \
		  ft_strnew.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c \
		  ft_tolower.c \
		  ft_toupper.c
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast -fno-builtin
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'
LDFLAGS	= -I. -L. -lft

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@ar -rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(DIR)
	@echo 'Compilation of $<'
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

%.out: %.c $(NAME) | $(DIR)
	$(CC) $(CFLAGS) $(DFLAGS) $< -o $@ $(LDFLAGS)

-include $(DEP)

.PHONY: all clean fclean re
