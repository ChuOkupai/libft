/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:56:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/26 14:23:08 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_bit.h"
#include "ft_type.h"

bool	ft_bit_at(const void *array, size_t index)
{
	return (((t_u8*)array)[index / 8] & (0x80 >> index % 8));
}
