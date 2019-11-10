/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 02:02:53 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:50:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t n;

	n = ft_strlen(s) + 1;
	while (n)
		if (s[--n] == (char)c)
			return ((char*)(s + n));
	return (NULL);
}
