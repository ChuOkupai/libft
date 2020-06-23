/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:48:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/21 01:46:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bit.h"
#include "ft_string.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	t_u8 map[32];

	ft_bit_map(map, 32, charset);
	while (*s && !ft_bit_at(map, *s))
		++s;
	return (*s ? (char*)s : NULL);
}
