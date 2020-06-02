/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 14:28:54 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 15:42:51 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <libft.h>

static int	print_error(void)
{
	ft_dprintf(2, "error: %s\n", strerror(errno));
	return (EXIT_FAILURE);
}

static char	*load_content(const char *path)
{
	t_file	*f;
	char	*s;

	if (!(f = ft_fopen(path, "r")))
		return (NULL);
	ft_setbuffer(f, NULL, 512);
	ft_getdelim(&s, FT_EOF, f);
	ft_fclose(f);
	if (errno)
		return (ft_memdel(s));
	return (s);
}

int			main(int ac, char **av)
{
	t_list	*l;
	char	*s;

	if (ac < 2 || ac > 3)
		return (0);
	if (!(s = load_content(av[1])))
		return (print_error());
	l = ft_list_split(s, (ac == 3 ? av[2] : NULL));
	ft_memdel(s);
	if (l)
	{
		ft_list_foreach(l, (t_gfunction) & ft_putendl);
		ft_list_clear(&l, &free);
	}
	else if (errno)
		return (print_error());
	return (0);
}
