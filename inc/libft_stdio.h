/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_stdio.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:09:51 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 13:16:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STDIO_H
# define LIBFT_STDIO_H

# ifndef __GNUC__
#  define __attribute__(x)
# endif	

# include <stddef.h>

/*
** Print a n bytes of a memory aera in hexadecimal representation and ASCII.
*/
void	*ft_print_memory(const void *s, size_t n);

/*
** Writes a formatted string write to the given file descriptor.
*/
int		ft_dprintf(int fd, const char *format, ...)
		__attribute__((format(printf, 2, 3)));

/*
** Stores the next line from the given file descriptor to line.
** If a line has been read, it returns a positive value.
** If EOF has been reached, it returns 0.
** This function return a negative value if an error occurs.
*/
int		ft_get_next_line(const int fd, char **line);

/*
** Writes a formatted string write to the standard output.
*/
int		ft_printf(const char *format, ...)
		__attribute__((format(printf, 1, 2)))
		__attribute__((nonnull(1)));

/*
** Writes a character to the standard output.
** Unicode is supported.
*/
void	ft_putchar(int c);

/*
** Writes a character to the given file descriptor.
** Unicode is supported.
*/
void	ft_putchar_fd(int c, int fd);

/*
** Writes a string with a newline to the standard output.
*/
void	ft_putendl(char *s);

/*
** Writes a string with a newline to the given file descriptor.
*/
void	ft_putendl_fd(char *s, int fd);

/*
** Writes an integer to the standard output.
*/
void	ft_putnbr(int n);

/*
** Writes an integer using a base to the standard output.
*/
void	ft_putnbr_base(int n, char const *base);

/*
** Writes an integer using a base to the given file descriptor.
*/
void	ft_putnbr_base_fd(int n, char const *base, int fd);

/*
** Writes an integer to the given file descriptor.
*/
void	ft_putnbr_fd(int n, int fd);

/*
** Writes a string to the standard output.
*/
void	ft_putstr(char *s);

/*
** Writes a string to the given file descriptor.
*/
void	ft_putstr_fd(char *s, int fd);

#endif
