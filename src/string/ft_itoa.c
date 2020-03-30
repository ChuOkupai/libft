/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 05:08:24 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 03:45:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

char	*ft_itoa(int n)
{
	char		*s;
	size_t		i;
	uint32_t	t;

	t = n < 0 ? -n : n;
	i = 1;
	while (t /= 10)
		i++;
	t = n < 0 ? -n : n;
	n = n < 0;
	if ((s = (char*)malloc((i + n + 1) * sizeof(char))))
	{
		s[0] = '-';
		s[i + n] = '\0';
		while (i--)
		{
			s[i + n] = t % 10 + '0';
			t /= 10;
		}
	}
	return (s);
}
