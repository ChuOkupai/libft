/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 04:28:09 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 15:13:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

char	*ft_strdup(const char *s)
{
	size_t n;

	n = ft_strlen(s);
	return (ft_memdup(s, n, n + 1, true));
}
