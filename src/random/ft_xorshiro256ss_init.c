/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xorshiro256ss_init.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:04:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/27 13:35:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_random.h"

static t_u64	splitmix64(t_u64 *state)
{
	t_u64 z;

	*state += 0x9e3779b97f4a7c15UL;
	z = *state;
	z = 0xbf58476d1ce4e5b9UL * (z ^ (z >> 30));
	z = 0x94d049bb133111ebUL * (z ^ (z >> 27));
	return (z ^ (z >> 31));
}

void			ft_xorshiro256ss_init(t_u64 *gen, t_u64 seed)
{
	t_u64 state;

	state = seed;
	gen[0] = splitmix64(&state);
	gen[1] = splitmix64(&state);
	gen[2] = splitmix64(&state);
	gen[3] = splitmix64(&state);
}
