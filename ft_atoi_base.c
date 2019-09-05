/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:47:59 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/05 01:52:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_issign(int c)
{
	return (c == '-' || c == '+');
}

static int	ft_check_base(char const *base, char *t)
{
	int i;

	i = -1;
	ft_memset(t, i, 128);
	while (base[++i] && ft_isgraph(base[i]) && !ft_issign(base[i])
		&& t[(int)base[i]] < 0)
		t[(int)base[i]] = i;
	return ((i < 2 || base[i]) ? 0 : i);
}

int			ft_atoi_base(char const *str, char const *base)
{
	char	t[128];
	int		n;
	int		sign;
	int		size;

	if ((size = ft_check_base(base, t)) < 2)
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (ft_issign(*str))
		str++;
	n = 0;
	while (t[(int)*str] > -1)
		n = n * size + t[(int)*str++];
	return (n * sign);
}
