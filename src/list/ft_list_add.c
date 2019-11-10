/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_add.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:50:55 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:31:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_add(t_list **l, t_list *elem)
{
	if (*l)
		ft_list_last(*l)->next = elem;
	else
		*l = elem;
}
