/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert_c.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 17:08:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 17:31:04 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string_utils.h"

int	ft_string_insert_c(t_string *s, size_t i, char c)
{
	if (i > s->size)
		i = s->size;
	if (!ft_string_check_capacity(s, 1))
		return (-1);
	ft_memmove(s->buf + i + 1, s->buf + i, s->size - i);
	s->buf[i] = c;
	s->buf[++s->size] = '\0';
	return (0);
}
