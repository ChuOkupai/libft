/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 03:17:11 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/12 03:49:26 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	ft_atoi(const char *str)
{
	int n;
	int negative;

	while (ft_isspace(*str))
		str++;
	negative = 0;
	if (*str == '-')
	{
		negative++;
		str++;
	}
	else if (*str == '+')
		str++;
	n = 0;
	while (ft_isdigit(*str))
		n = n * 10 + *str++ - '0';
	if (negative)
		n *= -1;
	return (n);
}
