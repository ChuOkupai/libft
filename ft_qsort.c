/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/03 23:45:39 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/12 12:27:10 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_qsort(void *tab, size_t len, size_t elem,
		int (cmp)(const void *, const void *))
{
	size_t	i;
	size_t	j;
	void	*p;

	if (len < 2)
		return ;
	p = tab + --len * elem;
	i = 0;
	j = 0;
	while (j < len)
	{
		if (cmp(tab + j * elem, p) < 0)
			ft_memswap(tab + i++ * elem, tab + j * elem, elem);
		j++;
	}
	if (cmp(tab + i * elem, tab + len * elem) > 0)
		ft_memswap(tab + i * elem, tab + len * elem, elem);
	ft_qsort(tab, i, elem, cmp);
	ft_qsort(tab + (i + 1) * elem, len - i, elem, cmp);
}
