/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:58:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 12:37:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#define CONTINUE "Press ENTER to continue..."

static char		*get_line(const char *label)
{
	char *line;

	ft_putstr(label);
	ft_get_next_line(0, &line);
	return (line);
}

static void		print_value(const void *content)
{
	ft_printf("%lu", (t_u64)content);
}

static void		edit_tree(t_rbtree **tree, char op)
{
	char		*s;
	void		*n;
	t_rbtree	*elem;
	bool		confirm;

	s = get_line("Enter a value: ");
	n = (void *)(s ? ft_strtoul(s, NULL, 10) : 0);
	ft_free(s);
	elem = ft_rbtree_search(*tree, n, &ft_compare_pointer);
	confirm = true;
	if (op == 'a')
	{
		if (elem)
			ft_putendl_fd("error: This value already exists!", 2);
		else if (!ft_rbtree_insert(tree, ft_rbtree_new(n), &ft_compare_pointer))
			ft_putendl_fd("error: Could not allocate memory!", 2);
		else
			confirm = false;
	}
	else if (elem)
		confirm = ft_rbtree_delete(tree, elem) == NULL;
	else
		ft_putendl_fd("error: Value not found!", 2);
	if (confirm)
		ft_free(get_line(CONTINUE));
}

static void		show_tree(t_rbtree *tree)
{
	ft_rbtree_print(tree, &print_value);
	ft_printf("size: %lu\n", ft_rbtree_size(tree));
	if (tree)
	{
		ft_printf("min: %lu\n", (t_u64)(ft_rbtree_min(tree)->content));
		ft_printf("max: %lu\n", (t_u64)(ft_rbtree_max(tree)->content));
	}
	ft_free(get_line(CONTINUE));
}

int				main(void)
{
	t_rbtree	*tree;
	char		*s;
	char		c;
	int			r;

	tree = NULL;
	r = 1;
	while (r > 0)
	{
		ft_putstr("\033[1;1H\033[2JRED BLACK TREE - MENU\na: add a new value\n"
		"d: delete a value\nv: tree view\nQuit with Ctrl+D\n\n > ");
		if ((r = ft_get_next_line(0, &s)) >= 0)
		{
			c = *s && !s[1] ? *s : '\0';
			ft_free(s);
			if (c == 'a' || c == 'd')
				edit_tree(&tree, c);
			else if (c == 'v')
				show_tree(tree);
			else if (c == 'q')
				break ;
		}
	}
	ft_rbtree_clear(&tree, NULL);
	return (0);
}
