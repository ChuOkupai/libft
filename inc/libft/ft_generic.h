/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:01:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 20:21:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GENERIC_H
# define FT_GENERIC_H

/*
** Compare two int.
** Returns a - b.
*/
int		ft_compare_int(const void *a, const void *b);

/*
** Display the content of type char to given file descriptor.
** The content is displayed in raw mode surrounded by single quotes.
*/
void	ft_print_char_fd(const void *character, int fd);

/*
** Display the content of type char on standard output.
** The content is displayed in raw mode surrounded by single quotes.
*/
void	ft_print_char(const void *character);

/*
** Display the content of type int to given file descriptor.
*/
void	ft_print_int_fd(const void *integer, int fd);

/*
** Display the content of type int on standard output.
*/
void	ft_print_int(const void *integer);

#endif
