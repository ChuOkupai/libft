/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:42:30 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/08 03:39:23 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*d;
	unsigned int	i;

	if ((d = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		i = 0;
		while (s[i])
		{
			d[i] = f(i, s[i]);
			i++;
		}
		d[i] = '\0';
	}
	return (d);
}
