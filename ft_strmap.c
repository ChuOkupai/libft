/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:33:10 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/08 04:08:29 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*d;
	size_t	i;

	if ((d = (char*)malloc((ft_strlen(s) + 1) * sizeof(char))))
	{
		i = 0;
		while (*s)
			d[i++] = f(*s++);
		d[i] = '\0';
	}
	return (d);
}
