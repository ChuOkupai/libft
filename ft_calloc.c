/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 14:05:59 by asoursou          #+#    #+#             */
/*   Updated: 2023/03/27 06:27:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*b;

	if (size && nmemb > (size_t)-1 / size)
		return (NULL);
	size *= nmemb;
	b = malloc(size);
	if (b)
		ft_bzero(b, size);
	return (b);
}
