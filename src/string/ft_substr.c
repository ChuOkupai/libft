/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 00:54:04 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:51:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char *d;

	if ((d = (char*)malloc((len + 1) * sizeof(char))))
	{
		ft_memcpy(d, s + start, len);
		d[len] = '\0';
	}
	return (d);
}
