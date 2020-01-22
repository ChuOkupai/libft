# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added

- ft_putnstr
Outputs no more than n characters of a string to standard output
- ft_putnstr_fd
Outputs no more than n characters of a string to given file descriptor
- ft_rbtree_size
Returns the size of a red black tree
- ft_sprintf
Outputs a formatted string to a string.
- ft_strsep
Locates the first occurrence of any character in the string delim or the terminating '\0' character and replaces it with a '\0'
- ft_vdprintf
Outputs a formatted string to given file descriptor using an argument list.
- ft_vprintf
Outputs a formatted string to standard output using an argument list.
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

## [1.0.0] - 2020-01-19

### Added

- First version

[Unreleased]: https://github.com/ChuOkupai/libft/compare/v1.0.0...unstable
[1.0.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.0.0
