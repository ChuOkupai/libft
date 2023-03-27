/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 02:52:50 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 05:47:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	const size_t	nl = ft_strlen(little);

	if (!nl)
		return ((char *)big);
	len = ft_bound_size_t(len, ft_strlen(big));
	while (len >= nl)
	{
		if (!ft_memcmp(big, little, nl))
			return ((char *)big);
		++big;
		--len;
	}
	return (NULL);
}
