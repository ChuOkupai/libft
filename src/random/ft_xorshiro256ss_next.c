/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xorshiro256ss_next.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:07:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/27 13:35:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_random.h"

static t_u64	rotl(const t_u64 x, int k)
{
	return (x << k) | (x >> (64 - k));
}

t_u64			ft_xorshiro256ss_next(t_u64 *gen)
{
	t_u64	r;
	t_u64	t;

	r = 9 * rotl(5 * gen[1], 7);
	t = gen[1] << 17;
	gen[2] ^= gen[0];
	gen[3] ^= gen[1];
	gen[1] ^= gen[2];
	gen[0] ^= gen[3];
	gen[2] ^= t;
	gen[3] = rotl(gen[3], 45);
	return (r);
}
