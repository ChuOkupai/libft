/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:33:10 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:49:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_string.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
