# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/27 21:22:22 by asoursou          #+#    #+#              #
#    Updated: 2020/06/02 00:11:26 by asoursou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# COMPILATION
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror -Wvla -Ofast -fno-builtin
DFLAGS	= -MP -MMD -MF $(DEP_DIR)/$*.d -MT $@
IFLAGS	= -I./inc -I./inc/libft -I./inc/private

# DIRECTORIES
BUILD	:= .build
DEP_DIR	:= $(BUILD)/dep
OBJ_DIR	:= $(BUILD)/obj
LOC_DIR := /usr/local
PRV		:= private
SUB_DIR	:= rbtree \
		   stdio
SUB_DIR += $(addsuffix /$(PRV), $(SUB_DIR))
SUB_DIR	+= bit \
		   btree \
		   ctype \
		   generic \
		   list \
		   memory \
		   string
DIRS	:= $(DEP_DIR) $(addprefix $(DEP_DIR)/, $(SUB_DIR)) \
		   $(OBJ_DIR) $(addprefix $(OBJ_DIR)/, $(SUB_DIR))

# FILES
FT		:= libft
NAME	:= $(FT).a
SUB_SRC	:= ft_bit_at.c \
		   ft_bit_map.c \
		   ft_bit_set.c \
		   ft_bit_to_string.c \
		   ft_bit_unset.c
SRC		:= $(addprefix bit/, $(SUB_SRC))
SUB_SRC	:= ft_btree_clear.c \
		   ft_btree_height.c \
		   ft_btree_infix.c \
		   ft_btree_insert.c \
		   ft_btree_new.c \
		   ft_btree_postfix.c \
		   ft_btree_prefix.c \
		   ft_btree_search.c \
		   ft_btree_size.c
SRC		+= $(addprefix btree/, $(SUB_SRC))
SUB_SRC	:= ft_isalnum.c \
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
		   ft_toprint.c \
		   ft_toupper.c
SRC		+= $(addprefix ctype/, $(SUB_SRC))
SUB_SRC	:= ft_compare_int.c \
		   ft_print_char.c \
		   ft_print_char_fd.c \
		   ft_print_int.c \
		   ft_print_int_fd.c
SRC		+= $(addprefix generic/, $(SUB_SRC))
SUB_SRC	:= ft_list_at.c \
		   ft_list_clear.c \
		   ft_list_extract.c \
		   ft_list_foreach.c \
		   ft_list_insert.c \
		   ft_list_last.c \
		   ft_list_new.c \
		   ft_list_pop.c \
		   ft_list_print.c \
		   ft_list_print_fd.c \
		   ft_list_push.c \
		   ft_list_push_back.c \
		   ft_list_remove_if.c \
		   ft_list_rev.c \
		   ft_list_search.c \
		   ft_list_size.c \
		   ft_list_sort.c \
		   ft_list_split.c
SRC		+= $(addprefix list/, $(SUB_SRC))
SUB_SRC	:= ft_bzero.c \
		   ft_calloc.c \
		   ft_memccpy.c \
		   ft_memchr.c \
		   ft_memcmp.c \
		   ft_memcpy.c \
		   ft_memdel.c \
		   ft_memdeltab.c \
		   ft_memdup.c \
		   ft_memmove.c \
		   ft_memset.c
SRC		+= $(addprefix memory/, $(SUB_SRC))
SUB_SRC	:= ft_rbtree_remove_guard.c \
		   ft_rbtree_rotate_left.c \
		   ft_rbtree_rotate_right.c \
		   ft_rbtree_transplant.c
SUB_SRC	:= $(addprefix $(PRV)/, $(SUB_SRC))
SUB_SRC	+= ft_rbtree_clear.c \
		   ft_rbtree_delete.c \
		   ft_rbtree_infix.c \
		   ft_rbtree_insert.c \
		   ft_rbtree_max.c \
		   ft_rbtree_min.c \
		   ft_rbtree_new.c \
		   ft_rbtree_postfix.c \
		   ft_rbtree_prefix.c \
		   ft_rbtree_print.c \
		   ft_rbtree_print_fd.c \
		   ft_rbtree_search.c \
		   ft_rbtree_size.c
SRC		+= $(addprefix rbtree/, $(SUB_SRC))
SUB_SRC	:= ft_file_utils.c \
		   ft_printf_parse_cnos.c \
		   ft_printf_parse_dpux.c \
		   ft_printf_parse_utils.c \
		   ft_printf_parse.c \
		   ft_printf_print_utils.c \
		   ft_printf_wchar.c
SUB_SRC	:= $(addprefix $(PRV)/, $(SUB_SRC))
SUB_SRC	+= ft_asprintf.c \
		   ft_clearerr.c \
		   ft_dprintf.c \
		   ft_fclose.c \
		   ft_feof.c \
		   ft_ferror.c \
		   ft_fflush.c \
		   ft_fgetc.c \
		   ft_fileno.c \
		   ft_fopen.c \
		   ft_fputc.c \
		   ft_fputs.c \
		   ft_fread.c \
		   ft_fwrite.c \
		   ft_get_next_line.c \
		   ft_getdelim.c \
		   ft_getline.c \
		   ft_print_memory.c \
		   ft_printf.c \
		   ft_putchar.c \
		   ft_putchar_fd.c \
		   ft_putendl.c \
		   ft_putendl_fd.c \
		   ft_putnbr.c \
		   ft_putnbr_base.c \
		   ft_putnbr_base_fd.c \
		   ft_putnbr_fd.c \
		   ft_putnstr.c \
		   ft_putnstr_fd.c \
		   ft_putrawstr.c \
		   ft_putrawstr_fd.c \
		   ft_putstr.c \
		   ft_putstr_fd.c \
		   ft_setbuffer.c \
		   ft_snprintf.c \
		   ft_sprintf.c \
		   ft_vasprintf.c \
		   ft_vdprintf.c \
		   ft_vprintf.c \
		   ft_vsnprintf.c \
		   ft_vsprintf.c
SRC		+= $(addprefix stdio/, $(SUB_SRC))
SUB_SRC	:= ft_atoi.c \
		   ft_atol.c \
		   ft_itoa.c \
		   ft_itoa_base.c \
		   ft_stpcpy.c \
		   ft_stpncpy.c \
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
		   ft_strpbrk.c \
		   ft_strrchr.c \
		   ft_strrev.c \
		   ft_strsep.c \
		   ft_strsplit.c \
		   ft_strstr.c \
		   ft_strsub.c \
		   ft_strtol.c \
		   ft_strtoul.c \
		   ft_strtrim.c \
		   ft_strwhile.c \
		   ft_strwhilenot.c
SRC		+= $(addprefix string/, $(SUB_SRC))
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

install: $(NAME)
	install $< $(LOC_DIR)/lib
	install -m 644 inc/$(FT).h $(LOC_DIR)/include
	cp -r inc/$(FT) $(LOC_DIR)/include

uninstall:
	rm -f $(LOC_DIR)/lib/$(NAME)
	rm -rf $(LOC_DIR)/include/$(FT) $(LOC_DIR)/include/$(FT).h

$(BUILD):
	@echo 'Creation of $@ directory'
	@mkdir $@ $(DIRS)

$(OBJ_DIR)/%.o: src/%.c | $(BUILD)
	@echo 'Compilation of $<'
	@$(CC) $(CFLAGS) $(DFLAGS) $(IFLAGS) -c $< -o $@

-include $(DEP)

.PHONY: all clean fclean re install uninstall
