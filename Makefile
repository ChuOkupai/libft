# DIRECTORIES
DEP_DIR	= dep
OBJ_DIR	= obj

# FILES
NAME	= libft.a
SRC		= ft_atoi_base.c \
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
		  ft_strcpy.c \
		  ft_strdup.c \
		  ft_strjoin.c \
		  ft_strlcat.c \
		  ft_strlcpy.c \
		  ft_strlen.c \
		  ft_strncat.c \
		  ft_strncmp.c \
		  ft_strncpy.c \
		  ft_strstr.c
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@ar -rcs $@ $(OBJ)

all: $(NAME)

clean:
	@echo 'Deletion of dependencies and objects'
	@rm -rf $(DEP_DIR) $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(DEP_DIR):
	mkdir $@

$(OBJ_DIR):
	mkdir $@

$(OBJ_DIR)/%.o: %.c | $(DEP_DIR) $(OBJ_DIR)
	@echo '$(CC) $<'
	@$(CC) $(CFLAGS) $(DFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
