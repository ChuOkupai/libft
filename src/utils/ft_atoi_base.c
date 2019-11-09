/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/05 00:47:59 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 13:50:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_base(char const *str, char const *base)
{
	char	t[128];
	int		n;
	int		sign;
	int		i;

	i = -1;
	ft_memset(t, i, 128);
	while (base[++i] && ft_isgraph(base[i]) && base[i] != '-' && base[i] != '+'
		&& t[(int)base[i]] < 0)
		t[(int)base[i]] = i;
	if (i < 2 || base[i])
		return (0);
	while (ft_isspace(*str))
		str++;
	sign = (*str == '-') ? -1 : 1;
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (t[(int)*str] >= 0)
		n = n * i + t[(int)*str++];
	return (n * sign);
}
