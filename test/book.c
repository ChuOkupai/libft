/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   book.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/24 20:03:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 22:07:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <libft.h>

typedef struct s_book t_book;
struct s_book
{
	char	*title;
	char	*author;
	int		year;
};

static t_book	*book_new(char *title, char *author, int year)
{
	t_book *b;

	if (!(b = malloc(sizeof(t_book))))
		return (NULL);
	b->title = title;
	b->author = author;
	b->year = year;
	return (b);
}

static void		book_print(const t_book *b)
{
	ft_putchar('[');
	ft_putstr(b->title);
	ft_printf(", ");
	ft_putstr(b->author);
	ft_printf(", ");
	ft_putnbr(b->year);
	ft_putchar(']');
}

static int		book_cmp_title(const t_book *a, const t_book *b)
{
	return (ft_strcmp(a->title, b->title));
}

static int		book_cmp_author(const t_book *a, const t_book *b)
{
	return (ft_strcmp(a->author, b->author));
}

static int		book_cmp_year(const t_book *a, const t_book *b)
{
	return (a->year - b->year);
}

int				main(void)
{
	t_list *l;
	t_book *b;

	l = NULL;
	b = book_new("Don Quixote", "Miguel de Cervantes", 1612);
	ft_list_push(&l, ft_list_new(b));
	b = book_new("A Tale of Two Cities", "Charles Dickens", 1859);
	ft_list_push(&l, ft_list_new(b));
	b = book_new("The Lord of the Rings", "J. R. R. Tolkien", 1954);
	ft_list_push(&l, ft_list_new(b));
	ft_list_sort(&l, (t_gcompare) & book_cmp_title);
	ft_putendl("Sort by title:");
	ft_list_print(l, (t_gprint) & book_print);
	ft_list_sort(&l, (t_gcompare) & book_cmp_author);
	ft_putendl("\nSort by author:");
	ft_list_print(l, (t_gprint) & book_print);
	ft_list_sort(&l, (t_gcompare) & book_cmp_year);
	ft_putendl("\nSort by year:");
	ft_list_print(l, (t_gprint) & book_print);
	ft_list_clear(&l, &free);
	return (0);
}
