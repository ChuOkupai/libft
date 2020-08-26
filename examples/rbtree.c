/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:58:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/26 14:29:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

#define CONTINUE "Press ENTER to continue..."

static char		*get_line(char *label)
{
	char *line;

	ft_putstr(label);
	ft_get_next_line(0, &line);
	return (line);
}

static t_rbtree	*new_value(int n)
{
	t_rbtree	*elem;
	int			*value;

	if (!(value = malloc(sizeof(int))))
		return (NULL);
	if (!(elem = ft_rbtree_new(value)))
		return (ft_memdel(value));
	*value = n;
	return (elem);
}

static void		edit_tree(t_rbtree **tree, char op)
{
	char		*s;
	int			n;
	t_rbtree	*elem;
	bool		confirm;

	s = get_line("Enter a value: ");
	n = s ? ft_atoi(s) : 0;
	ft_memdel(s);
	elem = ft_rbtree_search(*tree, &n, &ft_compare_int);
	confirm = true;
	if (op == 'a')
	{
		if (elem)
			ft_putendl_fd("error: This value already exists!", 2);
		else if (!ft_rbtree_insert(tree, new_value(n), &ft_compare_int))
			ft_putendl_fd("error: Could not allocate memory!", 2);
		else
			confirm = false;
	}
	else if (elem)
		confirm = ft_rbtree_delete(tree, elem, &free) == NULL;
	else
		ft_putendl_fd("error: Value not found!", 2);
	if (confirm)
		ft_memdel(get_line(CONTINUE));
}

static void		show_tree(t_rbtree *tree)
{
	ft_rbtree_print(tree, &ft_print_int);
	ft_printf("size: %lu\n", ft_rbtree_size(tree));
	if (tree)
	{
		ft_printf("min: %d\n", *((int *)(ft_rbtree_min(tree)->content)));
		ft_printf("max: %d\n", *((int *)(ft_rbtree_max(tree)->content)));
	}
	ft_memdel(get_line(CONTINUE));
}

int				main(void)
{
	t_rbtree	*tree;
	char		*s;
	char		c;

	tree = NULL;
	while (1)
	{
		ft_putstr("\033[1;1H\033[2JRED BLACK TREE - MENU\na: add a new value\n"
		"d: delete a value\nv: tree view\nq: quit\n\n > ");
		if (ft_get_next_line(0, &s) >= 0)
		{
			c = *s && !s[1] ? *s : 0;
			ft_memdel(s);
			if (c == 'a' || c == 'd')
				edit_tree(&tree, c);
			else if (c == 'v')
				show_tree(tree);
			else if (c == 'q')
				break ;
		}
	}
	ft_rbtree_clear(&tree, &free);
	return (0);
}
