/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:50:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/17 19:18:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

void	ft_list_push_back(t_list **l, t_list *elem)
{
	if (*l)
		ft_list_last(*l)->next = elem;
	else
		*l = elem;
}
