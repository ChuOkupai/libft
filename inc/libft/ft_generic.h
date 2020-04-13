/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:01:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/13 01:48:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GENERIC_H
# define FT_GENERIC_H

/*
** Display the content of char type to given file descriptor.
*/
void	ft_print_char_fd(const void *content, int fd);

/*
** Display the content of char type on standard output.
*/
void	ft_print_char(const void *content);

/*
** Display the content of int type to given file descriptor.
*/
void	ft_print_int_fd(const void *content, int fd);

/*
** Display the content of int type on standard output.
*/
void	ft_print_int(const void *content);

/*
** Display the content of string type to given file descriptor.
*/
void	ft_print_str_fd(const void *content, int fd);

/*
** Display the content of string type on standard output.
*/
void	ft_print_str(const void *content);

#endif
