/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_btree.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:30:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 16:31:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BTREE_H
# define LIBFT_BTREE_H

# include <stddef.h>

typedef struct s_btree	t_btree;
struct	s_btree
{
	void	*content;
	t_btree	*left;
	t_btree	*right;
};

/*
** Returns the height of the btree.
*/
size_t	ft_btree_height(t_btree *root);

/*
** Insert an element in a sorted list.
** Comparison is done with cmp.
*/
void	ft_btree_insert(t_btree **root, t_btree *elem,
		int (*cmp)(void *, void *));

/*
** Creates a new element with malloc.
*/
t_btree	*ft_btree_new(void *content);

/*
** Apply the given function f to all nodes in prefix order
*/
void	ft_btree_prefix(t_btree *root, void (*f)(void *));

/*
** Search an element from a binary tree which matches the reference content
** and returns a pointer to it.
** Comparison is done with cmp.
*/
t_btree	*ft_btree_search(t_btree *root, void *ref,
		int (*cmp)(void *ref, void *content));

/*
** Returns the size of the binary tree.
*/
size_t	ft_btree_size(t_btree *root);

/*
** Apply the given function f to all nodes in suffix order
*/
void	ft_btree_suffix(t_btree *root, void (*f)(void *));

#endif
