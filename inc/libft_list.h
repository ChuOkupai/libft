/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_list.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:02:20 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:25:18 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_LIST_H
# define LIBFT_LIST_H

# include <stddef.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

void			ft_list_add(t_list **l, t_list *elem);

t_list			*ft_list_at(t_list *l, size_t index);

void			ft_list_clear(t_list **l, void (*del)(void *));

t_list			*ft_list_extract(t_list **l, const void *ref,
				int (*cmp)(const void *ref, const void *content));

t_list			*ft_list_find(t_list *l, const void *ref,
				int (*cmp)(const void *ref, const void *content));

void			ft_list_foreach(t_list *l, void (*f)(void *));

void			ft_list_insert(t_list **l, t_list *elem,
				int (*cmp)(const void *, const void *));

t_list			*ft_list_last(t_list *l);

t_list			*ft_list_new(void *content);

void			ft_list_pop(t_list **l, void (*del)(void *));

void			ft_list_push(t_list **l, t_list *elem);

void			ft_list_remove_if(t_list **l, const void *ref,
				int (*cmp)(const void *ref, const void *content),
				void (*del)(void *));

void			ft_list_rev(t_list **l);

size_t			ft_list_size(t_list *l);

void			ft_list_sort(t_list **l,
				int (*cmp)(const void *, const void *));

#endif
