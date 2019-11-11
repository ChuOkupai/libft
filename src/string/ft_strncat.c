/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 05:28:36 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 15:20:32 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	char *d;

	d = s1 + ft_strlen(s1);
	while (n-- && *s2)
		*d++ = *s2++;
	*d = '\0';
	return (s1);
}
