/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fwrite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 01:36:51 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 16:37:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

#define BSIZE 3

int	main(int ac, char **av)
{
	t_file	*f;
	char	buf[BSIZE];

	if (ac != 2)
		return (0);
	if (!(f = ft_fopen(av[1], "w")))
		return (ft_dprintf(2, "error: fopen failed!\n"));
	ft_bzero(buf, BSIZE);
	ft_setvbuf(f, buf, FT_IOFBF, BSIZE);
	if (ft_fgetc(f) == FT_EOF)
		ft_printf("error 1\n");
	ft_fwrite("abcdef", sizeof(char), 2, f);
	ft_print_memory(buf, BSIZE);
	ft_fwrite("0123", sizeof(char), 4, f);
	ft_print_memory(buf, BSIZE);
	if (ft_ferror(f))
		ft_printf("error 2\n");
	ft_fclose(f);
	return (0);
}
