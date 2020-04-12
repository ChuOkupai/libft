/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:33:10 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 02:04:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft/ft_string.h"

char	*ft_strmap(const char *s, char (*f)(char))
{
	char	*d;
	size_t	n;

	n = ft_strlen(s);
	if ((d = (char*)malloc((n + 1) * sizeof(char))))
	{
		d[n] = '\0';
		while (n--)
			d[n] = f(s[n]);
	}
	return (d);
}
