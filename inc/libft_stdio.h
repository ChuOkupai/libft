/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_stdio.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:09:51 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/21 13:51:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STDIO_H
# define LIBFT_STDIO_H
# include <stddef.h>

/*
** Outputs a formatted string to given file descriptor.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_dprintf(int fd, const char *format,
	...) __attribute__((format(printf,2,3),nonnull(2)));

/*
** Stores next line from given file descriptor to line.
** If a line has been read, it returns a positive value.
** If EOF has been reached, it returns 0.
** This function return a negative value if an error occurs.
*/
int		ft_get_next_line(const int fd, char **line);

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
void	ft_putnstr(char *s, size_t n);

/*
** Outputs no more than n characters of a string to given file descriptor.
*/
void	ft_putnstr_fd(char *s, size_t n, int fd);

/*
** Outputs a string to standard output.
*/
void	ft_putstr(char *s);

/*
** Outputs a string to given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

/*
** Outputs a formatted string to a string.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_sprintf(char *str, const char *format,
	...) __attribute__((format(printf,2,3),nonnull(2)));

# if defined(_VA_LIST) || defined(_STDARG_H_) || defined(STDARG_H_)

/*
** Outputs a formatted string to given file descriptor using an argument list.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vdprintf(int fd, const char *format,
	va_list ap) __attribute__((nonnull(2)));

/*
** Outputs a formatted string to standard output using an argument list.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vprintf(const char *format,
	va_list ap) __attribute__((nonnull(1)));

/*
** Outputs a formatted string to a string using an argument list.
** Refer to the printf function to know the supported conversions, flags and
** modifiers.
*/
int		ft_vsprintf(char *str, const char *format,
	va_list ap) __attribute__((nonnull(1)));

# endif

#endif
