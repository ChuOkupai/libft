/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:00:15 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/06 00:38:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list **lst, t_list *new,
		int (*cmp)(const void *, const void *))
{
	if (!*lst || cmp(new->content, (*lst)->content) <= 0)
		ft_lstadd(lst, new);
	else
		ft_lstinsert(&(*lst)->next, new, cmp);
}
