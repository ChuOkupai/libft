/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fopen.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 01:36:51 by asoursou          #+#    #+#             */
/*   Updated: 2020/05/30 19:08:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <libft.h>

#define BUFSIZE 4
#define BUFSIZE2 6

int	main(int ac, char **av)
{
	t_file	*f;
	char	buf[BUFSIZE];
	char	buf2[BUFSIZE2 + 1];
	size_t	n;

	if (ac != 3)
		return (0);
	if (!(f = ft_fopen(av[1], av[2])))
		return (ft_dprintf(2, "fopen error: %s\n", strerror(errno)));
	ft_bzero(buf, BUFSIZE);
	ft_bzero(buf2, BUFSIZE2 + 1);
	ft_setvbuf(f, buf, FT_IOFBF, BUFSIZE);
	n = ft_fread(buf2, 1, BUFSIZE2, f);
	buf2[n] = '\0';
	ft_printf("> %ld\n", n);
	ft_printf("content > %.*s\n", (int)ft_strlen(buf2), buf2);
	ft_print_memory(buf, BUFSIZE);
	if (ft_feof(f))
		ft_printf("EOF\n");
	ft_fwrite("abc", 1, 3, f);
	ft_print_memory(buf, BUFSIZE);
	if (ft_ferror(f))
		ft_printf("error\n");
	ft_fclose(f);
	return (0);
}
