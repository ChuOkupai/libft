/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 00:10:44 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/04 00:21:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_memswap(void *a, void *b, size_t n)
{
	unsigned char t[n];

	ft_memcpy(t, a, n);
	ft_memcpy(a, b, n);
	ft_memcpy(b, t, n);
}
