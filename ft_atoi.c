/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 03:17:11 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 19:06:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int n;
	int sign;

	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		sign = -1;
		str++;
	}
	else
	{
		sign = 1;
		if (*str == '+')
			str++;
	}
	n = 0;
	while (ft_isdigit(*str))
		n = n * 10 + *str++ - '0';
	return (n * sign);
}
