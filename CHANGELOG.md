# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.3.0] - 2020-09-17
### Added
- **ft_btree_is_leaf**
- **ft_btree_merge**
- **ft_dlist_append**
- **ft_dlist_at**
- **ft_dlist_clear**
- **ft_dlist_first**
- **ft_dlist_foreach**
- **ft_dlist_insert**
- **ft_dlist_last**
- **ft_dlist_new**
- **ft_dlist_pop**
- **ft_dlist_print**
- **ft_dlist_print_fd**
- **ft_dlist_push**
- **ft_dlist_push_back**
- **ft_dlist_remove_if**
- **ft_dlist_remove_one**
- **ft_dlist_rev**
- **ft_dlist_search**
- **ft_dlist_size**
- **ft_dlist_split**
- **ft_list_merge**
- **ft_list_popl**
- **ft_list_pushl_back**
- **ft_list_pushl**
- **ft_list_remove_one**
- **ft_list_to_array**
- **ft_memmem**
- **ft_memsize**
- **ft_realloc**
- **ft_strjoin3**
- A progress indicator in Makefile

### Changed
- **ft_list_insert** returns the inserted element and the element can be NULL
- **ft_list_push/ft_list_push_back** is now taking the void* content instead of a t_list* element. The old functions still exists with **ft_list_pushl/ft_list_pushl_back**
- **ft_memdup** added a boolean variable to know if the allocated memory should be filled with 0
- **ft_print_memory** code optimization
- **ft_striter** has been replaced by **ft_strforeach**
- **ft_strjoin** the passed arguments can be NULL
- **ft_strstr/ft_strnstr** improved speed for small values
- **t_bool** has been replaced by the standard boolean type from stdbool.h
- Improved documentation
- Renamed *tab* variable in ft_memory to avoid conflict with ncurses
- Typo fixes

### Removed
- **ft_print_char_fd**
- **ft_print_char**
- **ft_print_int_fd**
- **ft_print_int**
- **ft_striteri**
- **ft_strmap**

## [1.2.1] - 2020-06-30
### Fixed
- **ft_memccpy** now checks if the copied character causes its interruption
- **ft_putnbr_base_fd** memory was initialized incorrectly
- **ft_strtol** overflow and underflow detection are now fully functional
- **ft_strtoul** parsing was not working properly for some strings
- **ft_strtoul** errno was not set to EINVAL when the given string was invalid
- **ft_strtrim** the right part of the string was not trimmed correctly

## [1.2.0] - 2020-06-08

### Added
- **ft_asprintf**
- **ft_atol**
- **ft_bit_at**
- **ft_bit_map**
- **ft_bit_set**
- **ft_bit_to_string**
- **ft_bit_unset**
- **ft_compare_int**
- **ft_clearerr**
- **ft_fclose**
- **ft_fdopen**
- **ft_feof**
- **ft_ferror**
- **ft_fflush**
- **ft_fgetc**
- **ft_fileno**
- **ft_fopen**
- **ft_fputc**
- **ft_fputs**
- **ft_fread**
- **ft_fwrite**
- **ft_getdelim**
- **ft_getline**
- **ft_list_print**
- **ft_list_print_fd**
- **ft_memdup**
- **ft_print_char**
- **ft_print_char_fd**
- **ft_print_int**
- **ft_print_int_fd**
- **ft_rbtree_infix**
- **ft_rbtree_max**
- **ft_rbtree_min**
- **ft_rbtree_postfix**
- **ft_rbtree_prefix**
- **ft_rbtree_print**
- **ft_rbtree_print_fd**
- **ft_setbuffer**
- **ft_stpcpy**
- **ft_stpncpy**
- **ft_strtol**
- **ft_strwhile**
- **ft_strwhilenot**
- **ft_toprint**
- **ft_vasprintf**
- Installation mechanism
- License change from GPLv3 to LGPLv3

### Changed
- **ft_strsplit** now takes a set of delimiters as an argument instead of an unique character. When the given set is empty, all spaces are delimiters
- **ft_list_split** identical to the changes of **ft_strsplit**
- Various code refactoring
- Sub-header files are now located in **inc/libft/ft_*.h**
- Various return values added to simplify the source code

### Fixed
- **ft_strtoul** sets errno correctly when the value is out of range
- **ft_*_split** a segmentation fault occurred with non ASCII characters

## [1.1.1] - 2020-03-30

### Fixed
- **ft_btree_infix** was using a prefix traversal
- **ft_btree_suffix** was using a prefix traversal
- **ft_strrev** a segmentation fault occurred with an empty string

### Removed
- **ft_strlen** fast implementation due to memory access detection on uninitialized variables (which is technically true but incorrect)

## [1.1.0] - 2020-02-05

### Added
- **ft_putnstr**
- **ft_putnstr_fd**
- **ft_rbtree_delete**
- **ft_rbtree_size**
- **ft_snprintf**
- **ft_sprintf**
- **ft_strsep**
- **ft_vdprintf**
- **ft_vprintf**
- **ft_vsnprintf**
- **ft_vsprintf**

### Changed
- **ft_printf** buffer size decreased from 256 to 128
- simplified **ft_printf** source code
- less system calls in **ft_print_memory**

### Fixed
- wrong spacing with integer representation in **ft_print_memory**

### Removed
- **ft_list_load_file**
- return value in **ft_list_push** and **ft_list_push_back**
- utils/ directory in all #include instructions
- utils directory creation in Makefile

## [1.0.0] - 2020-01-19

### Added
- Initial version

[Unreleased]: https://github.com/ChuOkupai/libft/compare/v1.3.0...dev
[1.3.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.3.0
[1.2.1]: https://github.com/ChuOkupai/libft/releases/tag/v1.2.1
[1.2.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.2.0
[1.1.1]: https://github.com/ChuOkupai/libft/releases/tag/v1.1.1
[1.1.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.1.0
[1.0.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.0.0
