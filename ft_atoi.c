/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 03:17:11 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 05:17:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	long	sign;
	long	n;

	while (ft_isspace(*nptr))
		++nptr;
	sign = 1;
	if (*nptr == '-')
		sign = -sign;
	if (*nptr == '-' || *nptr == '+')
		++nptr;
	n = 0;
	while (ft_isdigit(*nptr))
		n = 10 * n + *nptr++ - '0';
	return (sign * n);
}
