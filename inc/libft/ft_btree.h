/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_btree.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 15:30:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/21 02:06:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BTREE_H
# define FT_BTREE_H
# define FT_REQUIRE_TYPE_BOOL
# define FT_REQUIRE_TYPE_GENERIC
# define FT_REQUIRE_TYPE_SIZE_T
# include "private/ft_include.h"

typedef struct s_btree	t_btree;
struct	s_btree
{
	void	*content;
	t_btree	*left;
	t_btree	*right;
};

/*
** Free a binary tree.
** The function pointer del can be NULL.
** Returns NULL.
*/
void	*ft_btree_clear(t_btree **root, t_gfunction del);

/*
** Returns the height of the binary tree.
*/
size_t	ft_btree_height(t_btree *root);

/*
** Apply the given function to all nodes in infix order
*/
void	ft_btree_infix(t_btree *root, t_gfunction function);

/*
** Insert an element in a sorted binary tree.
** Comparison is done with a comparison fonction pointer.
** Returns a pointer to the inserted element.
*/
t_btree	*ft_btree_insert(t_btree **root, t_btree *element, t_gcompare cmp);

/*
** Returns true if the given node is a leaf.
*/
t_bool	ft_btree_is_leaf(t_btree *node);

/*
** Merge root with its left and right child.
** The left and right pointer of the root are overwritten by the new values.
** Returns root.
*/
t_btree	*ft_btree_merge(t_btree *root, t_btree *left, t_btree *right);

/*
** Creates a new element with malloc.
** Returns NULL on error.
*/
t_btree	*ft_btree_new(void *content);

/*
** Apply the given function to all nodes in postfix order
*/
void	ft_btree_postfix(t_btree *root, t_gfunction function);

/*
** Apply the given function to all nodes in prefix order
*/
void	ft_btree_prefix(t_btree *root, t_gfunction function);

/*
** Search an element from a binary tree which matches the reference content
** and returns a pointer to it.
** Comparison is done with cmp.
** Returns NULL if not found.
*/
t_btree	*ft_btree_search(t_btree *root, void *reference, t_gcompare cmp);

/*
** Returns the size of the binary tree.
*/
size_t	ft_btree_size(t_btree *root);

#endif
