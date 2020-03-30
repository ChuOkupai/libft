/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:06:10 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/30 03:57:52 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	return (n ? (uint8_t)(*s1) - (uint8_t)(*s2) : 0);
}
