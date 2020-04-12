/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/17 20:17:28 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 02:04:01 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/ft_string.h"

char	*ft_strsep(char **stringp, const char *delim)
{
	char *src;

	src = *stringp;
	while (!ft_strchr(delim, **stringp))
		++*stringp;
	if (**stringp)
		*(*stringp)++ = '\0';
	else
		*stringp = NULL;
	return (src);
}
