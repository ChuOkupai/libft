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
- [ft_const](inc/libft/ft_const.h "libft/ft_const.h") - Contains some useful constants
- [ft_ctype](inc/libft/ft_ctype.h "libft/ft_ctype.h") - Character tests and conversions
- [ft_dlist](inc/libft/ft_dlist.h "libft/ft_dlist.h") - Implementation of doubly linked lists
- [ft_generic](inc/libft/ft_generic.h "libft/ft_generic.h") - Provide generic functions for common standard data types
- [ft_list](inc/libft/ft_list.h "libft/ft_list.h") - Implementation of singly linked lists
- [ft_memory](inc/libft/ft_memory.h "libft/ft_memory.h") - Functions concerning memory manipulation
- [ft_random](inc/libft/ft_random.h "libft/ft_random.h") - Pseudorandom number generator
- [ft_rbtree](inc/libft/ft_rbtree.h "libft/ft_rbtree.h") - Implementation of red black trees
- [ft_stdio](inc/libft/ft_stdio.h "libft/ft_stdio.h") - Basic I/O interface
- [ft_string](inc/libft/ft_string.h "libft/ft_string.h") - Fonctions concerning string manipulation
- [ft_type](inc/libft/ft_type.h "libft/ft_type.h") - Contains data types definition including generic functions pointers

## Features
- A faster printf implementation (only conversions c, d, n, o, p, s, u, and x are supported)
- ft_get_next_line can read a file descriptor line by line, either on standard input or on a file
- Implementation of generic data structures that do not exist in the libc
- A better rand function, using the Xoroshiro256** algorithm
- String implementation with dynamic buffer

## Build instructions
This project can be compiled on both Linux and Mac by the following command in a terminal:
```shell
make
```

It generates a static C library named libft.a.

## Installation
In order to install the libft on your system, you can use the command:
```shell
sudo make install
```

It can be removed with:
```shell
sudo make uninstall
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

## Examples
Code samples can be compiled with:
```shell
make test
```

Then, all compiled binaries are stored in the examples/bin directory.
You are free to test the programs and access the source code.

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
This project is licensed under the LGPLv3 License - see the [LICENSE](LICENSE) file for details
