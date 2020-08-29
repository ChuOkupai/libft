/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 02:52:50 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/29 19:46:30 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strnstr(const char *h, const char *n, size_t l)
{
	size_t hl;

	if ((hl = ft_strlen(h)) < l)
		l = hl;
	return (ft_memmem(h, l, n, ft_strlen(n)));
}
