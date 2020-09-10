/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 00:38:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/06 12:19:53 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_ctype.h"
#include "ft_memory.h"
#include "ft_stdio.h"

/*
** Size of a row in bytes for display.
** Must be strictly greater than 0 and divisible by 2.
*/
#define SIZE	16
#if SIZE < 1 || SIZE % 2
# error "Illegal value set for variable SIZE"
#endif

static char	*padding(char *b, size_t n)
{
	return (n ? (char*)ft_memset(b, ' ', n) + n : b);
}

static void	copy(const char *s, char *b, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (n - i >= 2)
			b += ft_sprintf(b, "%.2hhx%.2hhx ", s[i], s[i + 1]);
		else
			b += ft_sprintf(b, "%.2hhx   ", s[i]);
		i += 2;
	}
	b = padding(b, 5 * ((SIZE - i) / 2));
	*b++ = '|';
	i = 0;
	while (i < n)
	{
		*b++ = ft_isprint(s[i]) ? s[i] : '.';
		++i;
	}
	b = padding(b, SIZE - i);
	*b = '|';
}

void		*ft_print_memory(const void *s, size_t n)
{
	const char	*t;
	char		b[2 * sizeof(size_t) + 3 * SIZE + (SIZE + 1) / 2 + 7];
	size_t		i;
	size_t		len;

	len = 2 * sizeof(size_t) + 3 * SIZE + (SIZE + 1) / 2 + 7;
	b[len - 1] = '\n';
	t = s;
	i = 0;
	while (i < n)
	{
		copy(t, b + ft_sprintf(b, "0x%.*lx: ", (int)(2 * sizeof(size_t)),
		(size_t)t), (n - i < SIZE ? n - i : SIZE));
		(void)(write(STDOUT_FILENO, b, len) + 1);
		t += SIZE;
		i += SIZE;
	}
	return ((void*)s);
}
