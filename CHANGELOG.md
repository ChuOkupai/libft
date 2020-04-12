# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.0.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Added
- **ft_asprintf**
- **ft_atol**
- **ft_bit_at**
- **ft_bit_map**
- **ft_bit_set**
- **ft_bit_unset**
- **ft_rbtree_max**
- **ft_rbtree_min**
- **ft_stpcpy**
- **ft_stpncpy**
- **ft_strtol**
- **ft_strwhile**
- **ft_vasprintf**
- **ft_memdup**
- **ft_list_print**
- Installation mechanism

### Changed
- **ft_strsplit** now takes a set of delimiters as an argument instead of an unique character. When the given set is empty, all spaces are delimiters
- **ft_list_split** identical to the changes of **ft_strsplit**
- Various code refactoring
- Sub-header files are now located in **inc/libft/ft_*.h**
- Various return values added to simplify the source code

### Fixed
- **ft_strtoul** sets errno correctly when the value is out of range

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

[Unreleased]: https://github.com/ChuOkupai/libft/compare/v1.1.1...dev
[1.1.1]: https://github.com/ChuOkupai/libft/releases/tag/v1.1.1
[1.1.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.1.0
[1.0.0]: https://github.com/ChuOkupai/libft/releases/tag/v1.0.0
