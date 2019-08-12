/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 03:00:45 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/12 03:07:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char *s;

	if ((s = (char *)malloc(size)))
		return (ft_memset(s, '\0', size));
	return (NULL);
}
