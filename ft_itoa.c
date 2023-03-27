/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:11:37 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 06:36:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static t_u32	as_unsigned(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	count_digits(int n)
{
	t_u32	m;
	size_t	i;

	m = as_unsigned(n);
	i = 1;
	while (1)
	{
		m /= 10;
		if (!m)
			break ;
		++i;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*s;
	t_u32	i;
	t_u32	t;

	i = count_digits(n);
	t = as_unsigned(n);
	n = n < 0;
	s = malloc(i + n + 1);
	if (!s)
		return (s);
	*s = '-';
	s[i + n] = '\0';
	while (i--)
	{
		s[i + n] = t % 10 + '0';
		t /= 10;
	}
	return (s);
}
