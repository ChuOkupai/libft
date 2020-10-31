/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_erase.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/02 15:10:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 16:21:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

void	ft_string_erase(t_string *s, size_t i, size_t j)
{
	size_t size;

	if (!s->size || i >= s->size || i >= j)
		return ;
	if (j > s->size)
		j = s->size;
	size = s->size - j;
	if (size)
		ft_memmove(s->buf + i, s->buf + j, size);
	s->size -= j - i;
	s->buf[s->size] = '\0';
}
