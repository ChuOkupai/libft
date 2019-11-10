/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_stdio.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:09:51 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:24:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STDIO_H
# define LIBFT_STDIO_H

# include <stddef.h>

void	*ft_print_memory(const void *s, size_t n);

int		ft_dprintf(int fd, const char *format, ...);

int		ft_get_next_line(const int fd, char **line);

int		ft_printf(const char *format, ...);

void	ft_putchar(int c);

void	ft_putchar_fd(int c, int fd);

void	ft_putendl(char *s);

void	ft_putendl_fd(char *s, int fd);

void	ft_putnbr(int n);

void	ft_putnbr_base(int n, char const *base);

void	ft_putnbr_base_fd(int n, char const *base, int fd);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr(char *s);

void	ft_putstr_fd(char *s, int fd);

#endif
