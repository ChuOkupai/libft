/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 06:06:10 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/09 09:23:32 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	int r;

	while (n && *s1 && *s1 == *s2)
	{
		s1++;
		s2++;
		n--;
	}
	r = (n) ? (unsigned char)*s1 - (unsigned char)*s2 : 0;
	if (r)
		r = (r < 0) ? -1 : 1;
	return (r);
}
