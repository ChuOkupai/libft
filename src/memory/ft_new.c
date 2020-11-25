/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:45:03 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/25 12:05:18 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "ft_random.h"
#include "ft_type.h"

#define PRECISION 1e6

static t_u64 g_prb = 0;
static void (*g_handler)(void) = NULL;

bool	ft_new_canfail(void)
{
	return (g_prb != 0);
}

void	ft_new_setfail(double p)
{
	if (p < 0.0)
		p = 0.0;
	else if (p > 1.0)
		p = 1.0;
	g_prb = p * (double)PRECISION;
}

void	ft_new_sethook(void (*handler)(void))
{
	g_handler = handler;
}

void	*ft_new(size_t size)
{
	void *data;

	if (g_prb && ft_rand() % (t_u64)PRECISION < g_prb)
	{
		errno = ENOMEM;
		data = NULL;
	}
	else
		data = malloc(size);
	if (!data && g_handler)
		g_handler();
	return (data);
}
