/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 04:28:09 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/13 01:55:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char	*d;
	size_t	n;

	n = ft_strlen(s1) + 1;
	if ((d = (char *)malloc(n * sizeof(char))))
		ft_memcpy(d, s1, n);
	return (d);
}
