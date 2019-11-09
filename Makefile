# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 21:22:22 by asoursou          #+#    #+#              #
#    Updated: 2019/11/09 14:37:48 by asoursou         ###   ########.fr        #
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
SUB_DIR	= ctype \
		  list \
		  memory \
		  stdio \
		  string \
		  utils
DIRS	:= $(DEP_DIR) $(addprefix $(DEP_DIR)/, $(SUB_DIR)) \
		   $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILES
NAME	= libft.a
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
		  ft_list_find.c \
		  ft_list_foreach.c \
		  ft_list_insert.c \
		  ft_list_last.c \
		  ft_list_new.c \
		  ft_list_pop.c \
		  ft_list_push.c \
		  ft_list_remove_if.c \
		  ft_list_rev.c \
		  ft_list_size.c \
		  ft_list_sort.c
MEMORY	= ft_bzero.c \
		  ft_calloc.c \
		  ft_memccpy.c \
		  ft_memchr.c \
		  ft_memcmp.c \
		  ft_memcpy.c \
		  ft_memdel.c \
		  ft_memmove.c \
		  ft_memset.c
STDIO	= ft_print_memory.c \
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
STRING	= ft_split.c \
		  ft_strcat.c \
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
		  ft_strstr.c \
		  ft_strtrim.c \
		  ft_substr.c
UTILS	= ft_atoi.c \
		  ft_atoi_base.c \
		  ft_itoa.c \
		  ft_itoa_base.c
CTYPE	:= $(addprefix ctype/, $(CTYPE))
LIST	:= $(addprefix list/, $(LIST))
MEMORY	:= $(addprefix memory/, $(MEMORY))
STDIO	:= $(addprefix stdio/, $(STDIO))
STRING	:= $(addprefix string/, $(STRING))
UTILS	:= $(addprefix utils/, $(UTILS))
SRC		:= $(CTYPE) $(LIST) $(MEMORY) $(STDIO) $(STRING) $(UTILS)
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
