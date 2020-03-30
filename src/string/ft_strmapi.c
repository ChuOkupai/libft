/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:42:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 03:46:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>
#include "libft_string.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char		*d;
	uint32_t	n;

	n = ft_strlen(s);
	if ((d = (char*)malloc((n + 1) * sizeof(char))))
	{
		d[n] = '\0';
		while (n--)
			d[n] = f(n, s[n]);
	}
	return (d);
}
