/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generic.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 00:01:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/29 14:23:13 by asoursou         ###   ########.fr       */
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
** Compare two pointer
** Returns a positive value if a is greater than b, a negative value if a is
** less than b or even 0 if a == b.
*/
int		ft_compare_pointer(const void *a, const void *b);

/*
** Prints the address of the pointer to the standard output.
*/
void	ft_print_pointer(const void *pointer);

/*
** Prints the address of the pointer to the given file descriptor.
*/
void	ft_print_pointer_fd(const void *pointer, int fd);

#endif
