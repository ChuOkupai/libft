/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:16:57 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/16 10:47:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H
# include <stddef.h>

/*
** Converts the string str to its integer representation.
*/
int		ft_atoi(const char *str);

/*
** Converts the string str to its integer representation using a base.
*/
int		ft_atoi_base(char const *str, char const *base);

/*
** Find the greatest common factor of two integers.
*/
int		ft_gcd(int a, int b);

/*
** Converts an int to a string, and returns a pointer to it.
** The pointer must be free.
*/
char	*ft_itoa(int n);

/*
** Converts an int to a string in a base between 2 and 16,
** and returns a pointer to it.
** The pointer must be free.
*/
char	*ft_itoa_base(int n, int base);

#endif
