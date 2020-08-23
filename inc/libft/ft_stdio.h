/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:09:51 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 19:22:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_H
# define FT_STDIO_H
# define FT_REQUIRE_TYPE_SIZE_T
# define FT_REQUIRE_TYPE_SSIZE_T
# define FT_NEED_TYPE_VA_LIST
# include "private/ft_include.h"

/*
** End-of-file indicator
*/
# define FT_EOF	-1

typedef struct s_file	t_file;
struct s_file;

/*
** Outputs a formatted string to a new allocated string.
** The allocated pointer should be passed to free.
** If sufficient space cannot be allocated, return -1 and set ret to be
** a NULL pointer.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_asprintf(char **ret, const char *format,
	...) __attribute__((format(printf,2,3),nonnull(2)));

/*
** Clears end-of-file and error indicator.
*/
void	ft_clearerr(t_file *stream);

/*
** Outputs a formatted string to given file descriptor.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_dprintf(int fd, const char *format,
	...) __attribute__((format(printf,2,3),nonnull(2)));

/*
** Closes the file stream, emptying the buffer if necessary.
** Returns FT_EOF on error.
*/
int		ft_fclose(t_file *stream);

/*
** Associates a stream with an existing file descriptor.
** The mode must be compatible with the mode of the file descriptor.
** Modes "w" or "w+" do not cause truncation of the file.
** The file descriptor is not closed with ft_fclose.
** Returns NULL on error.
*/
t_file	*ft_fdopen(int fd, const char *mode);

/*
** Returns a non zero if end-of-file has been reached.
*/
int		ft_feof(t_file *stream);

/*
** Returns a non-zero value if an error has occurred.
*/
int		ft_ferror(t_file *stream);

/*
** Forces a stream to write all buffered data.
** Returns FT_EOF on error.
*/
int		ft_fflush(t_file *stream);

/*
** Obtains the next input character as an unsigned char converted to an int.
** Returns FT_EOF the stream is at end-of-file or a read error occurs.
*/
int		ft_fgetc(t_file *stream);

/*
** Returns the file descriptor associated with stream.
*/
int		ft_fileno(t_file *stream);

/*
** Opens a file according to the given path in binary mode.
** Supported mode :
** - "r" Open for reading. Fail if the file does not exist.
** - "w" Open for writing. Create the file if it does not exist.
** - "a" Open for writing. Always append new text at the end of file.
**       Creates the file if it does not exist.
** - "+" Following "r", "w", "a" opens for both reading and writing. This mode
**       isn't optimized because lseek is a forbidden function.
** - "x" Following "w" or "w+". Fail if the file already exists.
** Returns NULL on error.
*/
t_file	*ft_fopen(const char *path, const char *mode);

/*
** Writes the character c cast to an unsigned char to stream.
** Return the character written as an unsigned char cast to an int
** or FT_EOF on error.
*/
int		ft_fputc(int c, t_file *stream);

/*
** Writes the string s to stream, without its terminating null byte.
** Return a nonnegative number on success, or FT_EOF on error.
*/
int		ft_fputs(const char *s, t_file *stream);

/*
** Reads nitems objects, each size bytes long, from the stream,
** storing them at the location given by ptr.
** Return the number of objects read.
** A return value of 0 can be considered as an error (see ft_ferror).
*/
size_t	ft_fread(void *ptr, size_t size, size_t nitems, t_file *stream);

/*
** Writes nitems objects, each size bytes long, from the stream,
** obtaining them from the location given by ptr.
** Return the number of objects successfully written.
*/
size_t	ft_fwrite(const void *ptr, size_t size, size_t nitems, t_file *stream);

/*
** Stores next line from given file descriptor to line.
** If a line has been read, it returns a positive value.
** If FT_EOF has been reached, it returns 0.
** This function return a negative value if an error occurs.
*/
int		ft_get_next_line(const int fd, char **line);

/*
** The same function as ft_getline except that a line delimiter other than
** '\n' can be specified.
*/
ssize_t	ft_getdelim(char **line, int delim, t_file *stream);

/*
** Stores the next line from the given stream to line, without '\n'.
** If ft_setbuffer was called with a size of 0, the function always returns
** FT_EOF and sets line to a NULL pointer.
** The pointer must be freed by the user if allocated.
** Returns the size of the line, or FT_EOF in case of end-of-file or error.
*/
ssize_t	ft_getline(char **line, t_file *stream);

/*
** Print n bytes of a memory aera in its hexadecimal and ASCII representation.
*/
void	*ft_print_memory(const void *s, size_t n);

/*
** Outputs a formatted string to standard output.
** Supported conversions: c d n o p s u x
** Supported flags: # 0 - (space) + '
** Supported modifiers: hh h l ll
*/
int		ft_printf(const char *format,
	...) __attribute__((format(printf,1,2),nonnull(1)));

/*
** Outputs a character to standard output.
** Unicode is supported.
*/
void	ft_putchar(int c);

/*
** Outputs a character to given file descriptor.
** Unicode is supported.
*/
void	ft_putchar_fd(int c, int fd);

/*
** Outputs a string with a newline to standard output.
*/
void	ft_putendl(char *s);

/*
** Outputs a string with a newline to given file descriptor.
*/
void	ft_putendl_fd(char *s, int fd);

/*
** Outputs an integer to standard output.
*/
void	ft_putnbr(int n);

/*
** Outputs an integer to given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd);

/*
** Outputs an integer using a base to standard output.
*/
void	ft_putnbr_base(int n, char const *base);

/*
** Outputs an integer using a base to given file descriptor.
*/
void	ft_putnbr_base_fd(int n, char const *base, int fd);

/*
** Outputs no more than n characters of a string to standard output.
*/
void	ft_putnstr(const char *s, size_t n);

/*
** Outputs no more than n characters of a string to given file descriptor.
*/
void	ft_putnstr_fd(const char *s, size_t n, int fd);

/*
** Outputs a string to standard output.
*/
void	ft_putstr(char *s);

/*
** Outputs a string to given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

/*
** Requests a new buffer of size bytes for the given stream.
** If buf is NULL, a new buffer will be allocated when an IO operation is done.
** This function should be called before any I/O operations or it will discards
** all the content of the previous buffer.
*/
void	ft_setbuffer(t_file *stream, char *buf, size_t size);

/*
** Outputs a formatted string of maximum n characters to a string.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_snprintf(char *str, size_t n, const char *format,
		...) __attribute__((format(printf,3,4),nonnull(3)));

/*
** Outputs a formatted string to a string.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_sprintf(char *str, const char *format,
	...) __attribute__((format(printf,2,3),nonnull(2),nonnull(1)));

# ifdef FT_TYPE_VA_LIST

/*
** Disclaimer:
** Requires #include <stdarg.h> before calling this header to include functions
** that depend on va_list.
*/

/*
** Outputs a formatted string to a new allocated string using an argument list.
** The allocated pointer should be passed to free.
** If sufficient space cannot be allocated, return -1 and set ret to be
** a NULL pointer.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vasprintf(char **ret, const char *format,
	va_list ap) __attribute__((format(printf,2,0),nonnull(2)));

/*
** Outputs a formatted string to given file descriptor using an argument list.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vdprintf(int fd, const char *format,
	va_list ap) __attribute__((format(printf,2,0),nonnull(2)));

/*
** Outputs a formatted string to standard output using an argument list.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vprintf(const char *format,
	va_list ap) __attribute__((format(printf,1,0),nonnull(1)));

/*
** Outputs a formatted string of maximum n characters to a string using
** an argument list.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vsnprintf(char *str, size_t n, const char *format,
	va_list ap) __attribute__((format(printf,3,0),nonnull(3)));

/*
** Outputs a formatted string to a string using an argument list.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vsprintf(char *str, const char *format,
	va_list ap) __attribute__((format(printf,2,0),nonnull(2),nonnull(1)));

# endif
#endif
