/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 23:10:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 20:55:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <errno.h>
#include <string.h>

#define BSIZE 6

int	main(int ac, char **av)
{
	t_file	*f;
	t_file	*f2;
	char	buf[BSIZE];
	int		c;

	if (ac != 3)
		return (0);
	if (!(f = ft_fopen(av[1], "r")))
		return (ft_dprintf(2, "source file error: %s\n", strerror(errno)));
	if (!(f2 = ft_fopen(av[2], "w")))
	{
		ft_fclose(f);
		return (ft_dprintf(2, "destination file error: %s\n", strerror(errno)));
	}
	ft_bzero(buf, BSIZE);
	ft_setbuffer(f2, buf, BSIZE);
	while ((c = ft_fgetc(f)) != FT_EOF)
		ft_fputc(c, f2);
	ft_fclose(f);
	ft_fclose(f2);
	return (0);
}
