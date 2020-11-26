/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:50:39 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 14:58:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_type.h"

static void	set(t_u8 *b, t_u8 c, size_t n)
{
	if (!n)
		return ;
	*b = c;
	set(b + 1, c, n - 1);
}

void		*ft_memset(void *b, int c, size_t len)
{
	set(b, c, len);
	return (b);
}
