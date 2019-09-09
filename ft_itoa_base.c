/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:11:37 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/09 18:43:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_itoa_base(int n, int base)
{
	char			*b;
	char			*s;
	unsigned int	i;
	unsigned int	t;

	if (base < 2 || base > 16)
		return (NULL);
	b = "0123456789ABCDEF";
	t = ABS(n);
	i = 1;
	while (t /= base)
		i++;
	t = ABS(n);
	n = (n < 0 && base == 10);
	if ((s = (char*)malloc((i + n + 1) * sizeof(char))))
	{
		s[i + n] = '\0';
		while (i--)
		{
			s[i + n] = b[t % base];
			t /= base;
		}
		if (n)
			s[0] = '-';
	}
	return (s);
}
