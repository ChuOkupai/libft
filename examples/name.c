/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/02 20:08:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 12:15:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static char	*trim_name(char *s)
{
	char *s2;

	if ((s2 = ft_strtrim(s, FT_SPACE "!")) && !*s2)
		s2 = ft_delete(s2);
	ft_delete(s);
	return (s2);
}

int			main(void)
{
	char *s;

	ft_putstr("Name: ");
	if (ft_get_next_line(0, &s) >= 0 && (s = trim_name(s)))
	{
		ft_printf("Welcome, %s!\n", s);
		ft_delete(s);
	}
	else
		ft_putendl_fd("error: Could not read your name!", 2);
	return (0);
}
