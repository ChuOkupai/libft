/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rand.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:43:33 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/27 13:37:56 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_random.h"

static t_u64	*get_generator(void)
{
	static t_u64 gen[XORSHIRO_SIZE];

	return (gen);
}

t_u64			ft_rand(void)
{
	return (ft_xorshiro256ss_next(get_generator()));
}

void			ft_seed(t_u64 seed)
{
	ft_xorshiro256ss_init(get_generator(), seed);
}
