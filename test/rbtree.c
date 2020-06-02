/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rbtree.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 02:19:31 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/13 02:56:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <limits.h>
#include <stdlib.h>
#include <time.h>

static int	int_cmp(void *a, void *b)
{
	return (*((int*)a) - *((int*)b));
}

static int	*fill_tab(int n)
{
	int *t;
	int i;

	if (n < 0 || !(t = malloc(n * sizeof(int))))
		return (NULL);
	srand(time(NULL));
	i = -1;
	while (++i < n)
		t[i] = i * -(rand() % 2 ? -1 : 1);
	return (t);
}

int			main(int ac, char **av)
{
	t_rbtree	*r;
	t_rbtree	*e;
	int			*t;
	int			n;

	if (ac != 2)
		return (0);
	r = NULL;
	n = ft_atoi(av[1]);
	if (!(t = fill_tab(n)))
		return (1);
	while (n)
		if (!(e = ft_rbtree_new(t + n--)))
			break ;
		else
			ft_rbtree_insert(&r, e, &int_cmp);
	if (!n)
		ft_rbtree_print(r, &ft_print_int);
	ft_rbtree_clear(&r, NULL);
	free(t);
	return (0);
}
