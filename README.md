# libft

My own C library for 42 School projects

### External functions used

- free
- malloc
- read
- write

## Content description

- [ft_bit](inc/libft/ft_bit.h "libft/ft_bit.h") - Perform basic operations on bit arrays
- [ft_btree](inc/libft/ft_btree.h "libft/ft_btree.h") - Implementation of binary trees
- [ft_ctype](inc/libft/ft_ctype.h "libft/ft_ctype.h") - Character tests and conversions
- [ft_generic](inc/libft/ft_generic.h "libft/ft_generic.h") - Provide generic display functions for common standard data types
- [ft_list](inc/libft/ft_list.h "libft/ft_list.h") - Implementation of linked lists
- [ft_memory](inc/libft/ft_memory.h "libft/ft_memory.h") - Functions concerning memory manipulation
- [ft_rbtree](inc/libft/ft_rbtree.h "libft/ft_rbtree.h") - Implementation of red black trees
- [ft_stdio](inc/libft/ft_stdio.h "libft/ft_stdio.h") - Basic I/O interface
- [ft_string](inc/libft/ft_string.h "libft/ft_string.h") - Fonctions concerning string manipulation

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

## Installation

In order to install the libft on your system, you can use the command:
```shell
make install
```

It can be removed with:
```shell
make uninstall
```

- ⚠️ Note that it requires access privileges

## Usage

All header files are located in the inc directory.

The main header file is called libft.h, which can be included in your source files like this:
```c
#include "libft.h" // include all libft functions
```
But you can also use sub-header files if you do not want to include the entire library.
For example:
```c
#include "libft/ft_string.h" // include only libft string functions like ft_strlen
```

### Compile with libft

Assuming that you are using gcc as your compiler and *main.c* is located at the root of the directory:

```shell
gcc -I./inc main.c -L. -lft
```
...or if the library has been installed on your system:
```shell
gcc main.c -lft
```


## License

This project is licensed under the GPLv3 License - see the [LICENSE](LICENSE) file for details
