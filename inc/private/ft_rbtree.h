/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:30:10 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 15:26:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H
# include "libft_rbtree.h"

void	ft_rbtree_remove_guard(t_rbtree **root, t_rbtree *x, t_rbtree *g);

void	ft_rbtree_rotate_left(t_rbtree **root, t_rbtree *x);

void	ft_rbtree_rotate_right(t_rbtree **root, t_rbtree *y);

void	ft_rbtree_transplant(t_rbtree **root, t_rbtree *u, t_rbtree *v);

#endif
