/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:54:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 14:02:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H
# define FT_REQUIRE_TYPE_GENERIC
# define FT_REQUIRE_TYPE_SIZE_T
# include "private/ft_include.h"

enum		e_rbcolor
{
	RB_BLACK,
	RB_RED
};
typedef enum e_rbcolor	t_rbcolor;

typedef struct s_rbtree	t_rbtree;
struct		s_rbtree
{
	void		*content;
	t_rbcolor	color : 1;
	t_rbtree	*parent;
	t_rbtree	*left;
	t_rbtree	*right;
};

/*
** Free a red black tree.
** The function pointer del can be NULL.
** Returns NULL.
*/
void		*ft_rbtree_clear(t_rbtree **root, t_gfunction del);

/*
** Remove an element in a red black tree.
** Returns its content.
*/
void		*ft_rbtree_delete(t_rbtree **root, t_rbtree *element);

/*
** Apply the given function to all nodes in infix order
*/
void		ft_rbtree_infix(t_rbtree *root, t_gfunction function);

/*
** Insert an element in a red black tree.
** Comparison is done with a comparison fonction pointer.
** Do not insert duplicates.
** Returns a pointer to the inserted element.
*/
t_rbtree	*ft_rbtree_insert(t_rbtree **root, t_rbtree *element,
			t_gcompare cmp);

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
** Returns NULL on error.
*/
t_rbtree	*ft_rbtree_new(void *content);

/*
** Apply the given function to all nodes in postfix order
*/
void		ft_rbtree_postfix(t_rbtree *root, t_gfunction function);

/*
** Apply the given function to all nodes in prefix order
*/
void		ft_rbtree_prefix(t_rbtree *root, t_gfunction function);

/*
** Display the contents of the red black tree to given file descriptor.
** The print function is called to display the content of each item.
*/
void		ft_rbtree_print_fd(t_rbtree *root, t_gprint_fd print_fd, int fd);

/*
** Display the contents of the red black tree on standard output.
** The print function is called to display the content of each item.
*/
void		ft_rbtree_print(t_rbtree *root, t_gprint print);

/*
** Search an element from a red black tree which matches the reference content
** and returns a pointer to it.
** Comparison is done with a comparison fonction pointer.
** Returns NULL if not found.
*/
t_rbtree	*ft_rbtree_search(t_rbtree *root, const void *reference,
			t_gcompare cmp);

/*
** Returns the size of a red black tree.
*/
size_t		ft_rbtree_size(t_rbtree *root);

#endif
