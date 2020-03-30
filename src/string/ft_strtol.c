/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtol.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 00:04:04 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/18 00:55:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_ctype.h"
#include "libft_string.h"

long	ft_strtol(const char *str, char **endptr, int base)
{
	const char	*s;
	long		n;

	s = ft_strwhile(str, ft_isspace);
	if (*s == '-')
		n = -ft_strtoul(++s, endptr, base);
	else
	{
		if (*s == '+')
			++s;
		n = ft_strtoul(s, endptr, base);
	}
	if (!n && endptr && *endptr == s)
		*endptr = (char*)str;
	return (n);
}
