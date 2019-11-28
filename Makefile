# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 21:22:22 by asoursou          #+#    #+#              #
#    Updated: 2019/11/28 22:59:14 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Ofast -march=native -fno-builtin
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT '$@'

# DIRECTORIES
BUILD	= .build
DEP_DIR	= $(BUILD)/dep
OBJ_DIR = $(BUILD)/obj
SUB_DIR	= btree \
		  ctype \
		  list \
		  memory \
		  rbtree \
		  stdio \
		  string \
		  utils
DIRS	:= $(DEP_DIR) $(addprefix $(DEP_DIR)/, $(SUB_DIR)) \
		   $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILES
NAME	= libft.a
BTREE	= ft_btree_clear.c \
		  ft_btree_height.c \
		  ft_btree_infix.c \
		  ft_btree_insert.c \
		  ft_btree_new.c \
		  ft_btree_prefix.c \
		  ft_btree_search.c \
		  ft_btree_size.c \
		  ft_btree_suffix.c
CTYPE	= ft_isalnum.c \
		  ft_isalpha.c \
		  ft_isascii.c \
		  ft_isblank.c \
		  ft_iscntrl.c \
		  ft_isdigit.c \
		  ft_isgraph.c \
		  ft_islower.c \
		  ft_isprint.c \
		  ft_ispunct.c \
		  ft_isspace.c \
		  ft_isupper.c \
		  ft_isxdigit.c \
		  ft_tolower.c \
		  ft_toupper.c
LIST	= ft_list_add.c \
		  ft_list_at.c \
		  ft_list_clear.c \
		  ft_list_extract.c \
		  ft_list_foreach.c \
		  ft_list_insert.c \
		  ft_list_last.c \
		  ft_list_new.c \
		  ft_list_pop.c \
		  ft_list_push.c \
		  ft_list_remove_if.c \
		  ft_list_rev.c \
		  ft_list_search.c \
		  ft_list_size.c \
		  ft_list_sort.c \
		  ft_list_split.c
MEMORY	= ft_bzero.c \
		  ft_calloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memdeltab.c \
		  ft_memmove.c \
		  ft_memset.c
RBTREE	= ft_rbtree_clear.c \
		  ft_rbtree_insert.c \
		  ft_rbtree_new.c \
		  ft_rbtree_rotate_left.c \
		  ft_rbtree_rotate_right.c \
		  ft_rbtree_search.c
STDIO	= ft_dprintf.c \
		  ft_get_next_line.c \
		  ft_print_memory.c \
		  ft_printf_parse_cnos.c \
		  ft_printf_parse_dpux.c \
		  ft_printf_parse_utils.c \
		  ft_printf_parse.c \
		  ft_printf_print_utils.c \
		  ft_printf_wchar.c \
		  ft_printf.c \
		  ft_putchar.c \
		  ft_putchar_fd.c \
		  ft_putendl.c \
		  ft_putendl_fd.c \
		  ft_putnbr.c \
		  ft_putnbr_base.c \
		  ft_putnbr_base_fd.c \
		  ft_putnbr_fd.c \
		  ft_putstr.c \
		  ft_putstr_fd.c
STRING	= ft_strcat.c \
		  ft_strchr.c \
		  ft_strchrnul.c \
		  ft_strcmp.c \
		  ft_strcpy.c \
		  ft_strdup.c \
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
		  ft_strndup.c \
		  ft_strnstr.c \
		  ft_strrchr.c \
		  ft_strrev.c \
		  ft_strsplit.c \
		  ft_strstr.c \
		  ft_strsub.c \
		  ft_strtrim.c
UTILS	= ft_atoi.c \
		  ft_atoi_base.c \
		  ft_gcd.c \
		  ft_itoa.c \
		  ft_itoa_base.c
SRC		:= $(addprefix btree/, $(BTREE)) \
		   $(addprefix ctype/, $(CTYPE)) \
		   $(addprefix list/, $(LIST)) \
		   $(addprefix memory/, $(MEMORY)) \
		   $(addprefix rbtree/, $(RBTREE)) \
		   $(addprefix stdio/, $(STDIO)) \
		   $(addprefix string/, $(STRING)) \
		   $(addprefix utils/, $(UTILS))
DEP		:= $(SRC:%.c=$(DEP_DIR)/%.d)
OBJ		:= $(SRC:%.c=$(OBJ_DIR)/%.o)

$(NAME): $(OBJ)
	@echo 'Creation of $@'
	@ar -rcs $@ $^

all: $(NAME)

clean:
	rm -rf $(BUILD)

fclean: clean
	rm -f $(NAME)

re: fclean all

$(BUILD):
	@echo 'Creation of $(BUILD) directory'
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.c | $(BUILD)
	@echo 'Compilation of $(notdir $<)'
	@$(CC) $(CFLAGS) $(DFLAGS) -I./inc -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re
