/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 00:40:08 by asoursou          #+#    #+#             */
/*   Updated: 2019/09/06 00:44:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *lst, const void *content,
		int (*cmp)(const void *, const void *))
{
	if (!lst || !cmp(lst->content, content))
		return (lst);
	return (ft_lstfind(lst->next, content, cmp));
}
