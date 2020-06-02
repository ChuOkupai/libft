/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 01:36:51 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 23:58:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <fcntl.h>
#include <libft.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	main(int ac, char **av)
{
	char	*line;
	int		fd;
	int		r;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	line = NULL;
	while ((r = ft_get_next_line(fd, &line)) > 0)
	{
		ft_printf("|%s|\n", line);
		free(line);
	}
	if (r < 0)
		ft_printf("error: %s\n", strerror(errno));
	else
		ft_printf("|%s| < last\n", line);
	ft_memdel(line);
	close(fd);
	return (0);
}
