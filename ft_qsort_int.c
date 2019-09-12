/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_qsort_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 12:49:43 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/12 12:58:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

static void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void		ft_qsort_int(int *tab, size_t size)
{
	int		pivot;
	size_t	i;
	size_t	j;

	if (size < 2)
		return ;
	pivot = tab[--size];
	i = 0;
	j = 0;
	while (j < size)
	{
		if (tab[j] < pivot)
			ft_swap(&tab[i++], &tab[j]);
		j++;
	}
	if (tab[i] > tab[size])
		ft_swap(&tab[i], &tab[size]);
	ft_qsort_int(tab, i);
	ft_qsort_int(tab + i + 1, size - i);
}
