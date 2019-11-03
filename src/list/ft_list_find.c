/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:40:08 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/03 05:43:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_list_find(t_list *l, const void *reference,
		int (*cmp)(const void *, const void *))
{
	while (l && cmp(l->content, reference))
		l = l->next;
	return (l);
}
