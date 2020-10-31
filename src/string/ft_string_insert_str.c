/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert_str.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:34:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 17:18:24 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string_utils.h"

int	ft_string_insert_str(t_string *s, size_t i, const char *str)
{
	size_t n;

	if (i > s->size)
		i = s->size;
	if (!(n = ft_strlen(str)))
		return (0);
	if (!ft_string_check_capacity(s, n))
		return (-1);
	ft_memmove(s->buf + i + n, s->buf + i, s->size - i);
	ft_memcpy(s->buf + i, str, n);
	s->size += n;
	s->buf[s->size] = '\0';
	return (0);
}
