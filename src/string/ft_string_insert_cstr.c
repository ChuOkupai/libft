/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert_cstr.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 19:34:53 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/15 11:32:06 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string_utils.h"

void	ft_string_insert_cstr(t_string *s, const char *str, size_t i)
{
	size_t n;

	if (i > s->size || !(n = ft_strlen(str)) || !ft_string_check_capacity(s, n))
		return ;
	ft_memmove(s->buf + i + n, s->buf + i, s->size - i);
	ft_memcpy(s->buf + i, str, n);
	s->size += n;
	s->buf[s->size] = '\0';
}
