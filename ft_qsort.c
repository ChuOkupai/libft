/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:45:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/04 02:28:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(void *tab, size_t size, size_t n,
		int (cmp)(const void *, const void *))
{
	size_t	i;
	size_t	j;
	void	*p;

	if (size < 2)
		return ;
	size--;
	p = tab + size * n;
	i = 0;
	j = 0;
	while (j < size)
	{
		if (cmp(tab + j * n, p) < 0)
			ft_memswap(tab + i++ * n, tab + j * n, n);
		j++;
	}
	if (cmp(tab + i * n, tab + size * n) > 0)
		ft_memswap(tab + i * n, tab + size * n, n);
	ft_qsort(tab, i, n, cmp);
	ft_qsort(tab + (i + 1) * n, size - i, n, cmp);
}
