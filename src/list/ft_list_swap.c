/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_swap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 17:39:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 11:33:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap(t_list *l1, t_list *l2)
{
	void *t;

	if (!l1 || !l2)
		return ;
	t = l1->content;
	l1->content = l2->content;
	l2->content = t;
}
