/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 10:54:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/26 02:49:19 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H
# define FT_REQUIRE_TYPE_GENERIC
# define FT_REQUIRE_TYPE_SIZE_T
# include "private/ft_include.h"

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
** Returns NULL.
*/
void		*ft_rbtree_clear(t_rbtree **root, t_gfunction del);

/*
** Remove an element in a red black tree.
** If the function pointer del is NULL, content is returned, NULL otherwise.
*/
void		*ft_rbtree_delete(t_rbtree **root, t_rbtree *element,
			t_gfunction del);

/*
** Apply the given function to all nodes in infix order
*/
void		ft_rbtree_infix(t_rbtree *root, t_gfunction function);

/*
** Insert an element in a red black tree.
** Comparison is done with a comparison fonction pointer.
** Do not insert duplicates.
*/
void		ft_rbtree_insert(t_rbtree **root, t_rbtree *element,
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
*/
t_rbtree	*ft_rbtree_search(t_rbtree *root, const void *reference,
			t_gcompare cmp);

/*
** Returns the size of a red black tree.
*/
size_t		ft_rbtree_size(t_rbtree *root);

#endif
