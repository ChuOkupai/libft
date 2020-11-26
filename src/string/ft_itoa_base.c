/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 17:11:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:28:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_const.h"
#include "ft_memory.h"
#include "ft_type.h"

char	*ft_itoa_base(int n, int base)
{
	char	*b;
	char	*s;
	t_u32	i;
	t_u32	t;

	if (base < 2 || base > 16)
		return (NULL);
	b = FT_DIGIT "ABCDEF";
	t = n < 0 ? -n : n;
	i = 1;
	while (t /= base)
		++i;
	t = n < 0 ? -n : n;
	n = n < 0 && base == 10;
	if ((s = (char*)ft_malloc((i + n + 1) * sizeof(char))))
	{
		s[0] = '-';
		s[i + n] = '\0';
		while (i--)
		{
			s[i + n] = b[t % base];
			t /= base;
		}
	}
	return (s);
}
