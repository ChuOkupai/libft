/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 03:17:11 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/12 06:55:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int n;
	int negative;

	while (ft_isspace(*str))
		str++;
	if (*str == '-')
	{
		negative = 1;
		str++;
	}
	else
	{
		negative = 0;
		if (*str == '+')
			str++;
	}
	n = 0;
	while (ft_isdigit(*str))
		n = n * 10 + *str++ - '0';
	return ((negative) ? n * -1 : n);
}
