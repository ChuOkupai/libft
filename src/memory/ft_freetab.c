/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freetab.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:07:31 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 16:59:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_freetab(void **t, size_t n)
{
	if (!t)
		return (t);
	while (n)
		ft_free(t[--n]);
	return (ft_free(t));
}
