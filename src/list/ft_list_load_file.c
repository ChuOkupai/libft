/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_load_file.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/26 14:06:18 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/26 14:28:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft_list.h"
#include "libft_stdio.h"

t_list	*ft_list_load_file(const char *path)
{
	t_list	*list;
	char	*line;
	int		fd;
	int		r;

	list = NULL;
	if ((fd = open(path, O_RDONLY)) < 0)
		return (list);
	while ((r = ft_get_next_line(fd, &line)) > 0)
		if ((r = ft_list_push(&list, ft_list_new(line))) < 0)
			break ;
	close(fd);
	!r ? free(line) : ft_list_clear(&list, &free);
	ft_list_rev(&list);
	return (list);
}
