/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:40:08 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 15:59:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_list.h"

t_list	*ft_list_search(t_list *l, const void *ref,
		int (*cmp)(const void *ref, const void *content))
{
	while (l && cmp(ref, l->content))
		l = l->next;
	return (l);
}
