/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:42:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 12:12:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	char	*d;
	t_u32	i;

	if (!(d = (char*)ft_new((ft_strlen(s) + 1) * sizeof(char))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = f(i, s[i]);
		++i;
	}
	d[i] = '\0';
	return (d);
}
