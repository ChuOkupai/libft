/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getline.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/18 01:36:51 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 23:34:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	main(int ac, char **av)
{
	t_file	*f;
	char	*line;
	ssize_t	n;

	if (ac != 2)
		return (0);
	if (!(f = ft_fopen(av[1], "r")))
		return (ft_dprintf(2, "error: fopen failed!\n"));
	line = NULL;
	while ((n = ft_getline(&line, f)) > FT_EOF)
	{
		ft_printf("%ld > |%s|\n", n, line);
		line = ft_memdel(line);
	}
	if (ft_ferror(f))
		ft_printf("error\n");
	if (line)
	{
		ft_printf("final > |%s|\n", line);
		ft_memdel(line);
	}
	ft_fclose(f);
	return (0);
}
