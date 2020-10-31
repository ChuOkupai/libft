/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_to_array.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/06 11:44:46 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 12:12:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include "ft_memory.h"

void	**ft_list_to_array(t_list *l)
{
	void	**t;
	size_t	i;

	if (!(t = ft_new((ft_list_size(l) + 1) * sizeof(void *))))
		return (NULL);
	i = 0;
	while (l)
	{
		t[i++] = l->content;
		l = l->next;
	}
	t[i] = NULL;
	return (t);
}
