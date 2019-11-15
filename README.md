# libft

My own C library for 42 School projects

## Content description

- [btree](inc/libft_btree.h "libft_btree.h") - Implementation of binary trees
- [ctype](inc/libft_ctype.h "libft_ctype.h") - Character tests and conversions
- [list](inc/libft_list.h "libft_list.h") - Implementation of linked lists
- [macros](inc/libft_macros.h "libft_macros.h") - A collection of almost useful macros
- [memory](inc/libft_memory.h "libft_memory.h") - Functions concerning memory manipulation
- [stdio](inc/libft_stdio.h "libft_stdio.h") - Basic I/O interface
- [string](inc/libft_string.h "libft_string.h") - Fonctions concerning string manipulation
- [utils](inc/libft_utils.h "libft_utils.h") - Everything else

## Build instructions

This project can be compiled on both Linux and Mac by the following command in a terminal:
```shell
make
```

It generates a static C library named libft.a.

## Usage

All header files are located in the inc directory.

The main header file is called libft.h, which can be included in your source files like this:
```c
#include "libft.h"
```
But you can also use sub-header files if you do not want to include the entire library.

## License

This project is licensed under the GPLv3 License - see the [LICENSE.md](LICENSE.md) file for details
