/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_deletetab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:07:31 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 12:28:17 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	*ft_deletetab(void **t, size_t n)
{
	if (!t)
		return (t);
	while (n)
		ft_delete(t[--n]);
	return (ft_delete(t));
}
