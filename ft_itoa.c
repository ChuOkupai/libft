/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:11:37 by asoursou          #+#    #+#             */
/*   Updated: 2023/11/02 16:32:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	as_unsigned(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static size_t	count_digits(int n)
{
	unsigned int	m;
	size_t			i;

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
	char			*s;
	unsigned int	i;
	unsigned int	t;

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
