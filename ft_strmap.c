/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:33:10 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/08 04:21:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	size_t	n;

	n = ft_strlen(s) + 1;
	if ((d = (char*)malloc(n * sizeof(char))))
	{
		d[--n] = '\0';
		while (n--)
			d[n] = f(s[n]);
	}
	return (d);
}
