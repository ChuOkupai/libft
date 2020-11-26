/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_malloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 13:45:03 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 17:03:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include "ft_random.h"
#include "ft_type.h"

#define PRECISION 1e8

static t_u64		g_fail_prb = 0;
static t_ghandler	g_handler = NULL;

void		*ft_free(void *pointer)
{
	if (pointer)
		free(pointer);
	return (NULL);
}

double		ft_malloc_fail_rate(double p)
{
	double old;

	if (p < 0.0)
		p = 0.0;
	else if (p > 1.0)
		p = 1.0;
	old = (double)g_fail_prb / (double)PRECISION;
	g_fail_prb = p * (double)PRECISION;
	return (old);
}

t_ghandler	ft_malloc_hook(t_ghandler handler)
{
	t_ghandler old;

	old = g_handler;
	g_handler = handler;
	return (old);
}

void		*ft_malloc(size_t size)
{
	void *data;

	if (g_fail_prb && ft_rand() % (t_u64)PRECISION < g_fail_prb)
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
