/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_rbtree.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:54:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 15:14:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_RBTREE_H
# define LIBFT_RBTREE_H
# include <stddef.h>

typedef enum e_rbcolor	t_rbcolor;
enum		e_rbcolor
{
	RB_BLACK,
	RB_RED
};

typedef struct s_rbtree	t_rbtree;
struct		s_rbtree
{
	void		*content;
	t_rbtree	*parent;
	t_rbtree	*left;
	t_rbtree	*right;
	t_rbcolor	color : 1;
};

/*
** Free a red black tree.
** The function pointer del can be NULL.
*/
void		ft_rbtree_clear(t_rbtree **root, void (*del)(void *));

/*
** Remove an element in a red black tree.
** The function pointer del can be NULL.
*/
void		ft_rbtree_delete(t_rbtree **root, t_rbtree *element,
			void (*del)(void *));

/*
** Insert an element in a red black tree.
** Comparison is done with cmp.
** Do not insert duplicates.
*/
void		ft_rbtree_insert(t_rbtree **root, t_rbtree *element,
			int (*cmp)(void *, void *));

/*
** Returns the maximum element of a red black tree.
*/
t_rbtree	*ft_rbtree_max(t_rbtree *root);

/*
** Returns the minimum element of a red black tree.
*/
t_rbtree	*ft_rbtree_min(t_rbtree *root);

/*
** Creates a new element with malloc.
*/
t_rbtree	*ft_rbtree_new(void *content);

/*
** Search an element from a red black tree which matches the reference content
** and returns a pointer to it.
** Comparison is done with cmp.
*/
t_rbtree	*ft_rbtree_search(t_rbtree *root, void *reference,
			int (*cmp)(void *reference, void *content));

/*
** Returns the size of a red black tree.
*/
size_t		ft_rbtree_size(t_rbtree *root);

#endif
