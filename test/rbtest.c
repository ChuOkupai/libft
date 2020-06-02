/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtest.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 20:07:45 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 20:11:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	main(void)
{
	t_rbtree	*tree;
	int			t[3];

	tree = NULL;
	t[0] = 8;
	t[1] = 5;
	t[2] = 2;
	ft_rbtree_insert(&tree, ft_rbtree_new(t), &ft_compare_int);
	ft_rbtree_insert(&tree, ft_rbtree_new(t + 1), &ft_compare_int);
	ft_rbtree_insert(&tree, ft_rbtree_new(t + 2), &ft_compare_int);
	ft_rbtree_print(tree, &ft_print_int);
	ft_rbtree_clear(&tree, NULL);
	return (0);
}
