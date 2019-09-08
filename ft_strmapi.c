/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:42:30 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/08 04:21:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	n;

	n = ft_strlen(s) + 1;
	if ((d = (char*)malloc(n * sizeof(char))))
	{
		d[--n] = '\0';
		while (n--)
			d[n] = f(n, s[n]);
	}
	return (d);
}
