/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fread.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 01:36:51 by asoursou          #+#    #+#             */
/*   Updated: 2020/05/30 18:11:12 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

#define BSIZE 4
#define BSIZE2 4

int	main(int ac, char **av)
{
	FILE	*f;
	char	buf[BSIZE];
	char	s[BSIZE2 + 1];
	size_t	n;

	if (ac != 2)
		return (0);
	if (!(f = fopen(av[1], "r")))
		return (ft_dprintf(2, "error: fopen failed!\n"));
	ft_bzero(buf, BSIZE);
	setvbuf(f, buf, _IOFBF, BSIZE);
	while ((n = fread(s, 1, BSIZE2, f)))
	{
		s[n] = '\0';
		ft_printf("%lu: ", n);
		ft_putrawstr(s);
		ft_putchar('\n');
		ft_print_memory(buf, BSIZE);
	}
	fread(NULL, 0, 0, f);
	fclose(f);
	return (0);
}
