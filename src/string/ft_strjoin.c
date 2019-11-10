/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 01:45:07 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:48:32 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_memory.h"
#include "libft_string.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*d;
	size_t	n1;
	size_t	n2;

	n1 = ft_strlen(s1);
	n2 = ft_strlen(s2) + 1;
	if ((d = (char*)malloc((n1 + n2) * sizeof(char))))
	{
		ft_memcpy(d, s1, n1);
		ft_memcpy(d + n1, s2, n2);
	}
	return (d);
}
