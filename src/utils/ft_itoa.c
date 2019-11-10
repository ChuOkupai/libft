/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 05:08:24 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:52:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft_macros.h"

char	*ft_itoa(int n)
{
	char			*s;
	size_t			i;
	unsigned int	t;

	t = ABS(n);
	i = 1;
	while (t /= 10)
		i++;
	t = ABS(n);
	n = (n < 0);
	if ((s = (char*)malloc((i + n + 1) * sizeof(char))))
	{
		s[i + n] = '\0';
		while (i--)
		{
			s[i + n] = t % 10 + '0';
			t /= 10;
		}
		if (n)
			s[0] = '-';
	}
	return (s);
}
