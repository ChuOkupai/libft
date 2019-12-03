/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rbtree.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/16 13:30:10 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/03 12:42:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RBTREE_H
# define FT_RBTREE_H
# include "libft_rbtree.h"

void	ft_rbtree_rotate_left(t_rbtree **root, t_rbtree *x);

void	ft_rbtree_rotate_right(t_rbtree **root, t_rbtree *y);

#endif
