# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [1.1.1] - 2020-03-30

### Fixed
- ft_btree_infix was using a prefix traversal
- ft_btree_suffix was using a prefix traversal
- ft_strrev a segmentation fault occurred with an empty string

### Removed
- ft_strlen fast implementation due to memory access detection on uninitialized variables (which is technically true but incorrect)

## [1.1.0] - 2020-02-05

### Added

- ft_putnstr
Outputs no more than n characters of a string to standard output.
- ft_putnstr_fd
Outputs no more than n characters of a string to given file descriptor.
- ft_rbtree_delete
Remove an element in a red black tree.
- ft_rbtree_size
Returns the size of a red black tree.
- ft_snprintf
Outputs a formatted string of maximum n characters to a string.
- ft_sprintf
Outputs a formatted string to a string.
- ft_strsep
Locates the first occurrence of any character in the string delim or the terminating '\0' character and replaces it with a '\0'.
- ft_vdprintf
Outputs a formatted string to given file descriptor using an argument list.
- ft_vprintf
Outputs a formatted string to standard output using an argument list.
- ft_vsnprintf
Outputs a formatted string of maximum n characters to a string using an argument list.
- ft_vsprintf
Outputs a formatted string to a string using an argument list.

### Changed

- ft_printf buffer size decreased from 256 to 128
- simplified ft_printf source code
- less system calls in ft_print_memory

### Fixed

- wrong spacing with integer representation in ft_print_memory

### Removed

- ft_list_load_file
- return value in ft_list_push and ft_list_push_back
- utils/ directory in all #include instructions
- utils directory creation in Makefile

## [1.0.0] - 2020-01-19

### Added

- First version

[1.1.1]: https://github.com/ChuOkupai/libft/releases/tag/v1.1.1
[1.1.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.1.0
[1.0.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.0.0
