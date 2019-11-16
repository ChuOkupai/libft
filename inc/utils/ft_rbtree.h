/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:30:10 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/16 13:54:02 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H
# include "libft_rbtree.h"

# define GPARENT(N)	N->parent->parent
# define LUNCLE(N)	GPARENT(N)->left
# define RUNCLE(N)	GPARENT(N)->right

void	ft_rbtree_rotate_left(t_rbtree **root, t_rbtree *x);

void	ft_rbtree_rotate_right(t_rbtree **root, t_rbtree *y);

#endif
