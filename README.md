# libft

My own C library for 42 School projects

### External functions used

- free
- malloc
- read
- va_arg
- va_end
- va_start
- write

## Content description

- [btree](inc/libft_btree.h "libft_btree.h") - Implementation of binary trees
- [ctype](inc/libft_ctype.h "libft_ctype.h") - Character tests and conversions
- [list](inc/libft_list.h "libft_list.h") - Implementation of linked lists
- [memory](inc/libft_memory.h "libft_memory.h") - Functions concerning memory manipulation
- [rbtree](inc/libft_rbtree.h "libft_rbtree.h") - Implementation of red black trees
- [stdio](inc/libft_stdio.h "libft_stdio.h") - Basic I/O interface
- [string](inc/libft_string.h "libft_string.h") - Fonctions concerning string manipulation

## Features

- A faster printf implementation (only conversions c, d, n, o, p, s, u, and x are supported)

- ft_get_next_line can read a file descriptor line by line, either on standard input or on a file

- Implementation of generic data structures that do not exist in the libc

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
#include "libft.h" // include all libft functions
```
But you can also use sub-header files if you do not want to include the entire library.
For example:
```c
#include "libft_string.h" // include only libft string functions like ft_strlen
```

### Compile with libft

Assuming that you are using gcc as your compiler, that the library is compiled, and that the file named *main.c* is in the root of the directory:

```shell
gcc -I./inc main.c -L. -lft
```

## License

This project is licensed under the GPLv3 License - see the [LICENSE](LICENSE) file for details
