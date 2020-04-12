/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_at.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:56:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 19:32:05 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_bit.h"

bool	ft_bit_at(const void *array, size_t index)
{
	return (((uint8_t *)array)[index / 8] & (0x80 >> index % 8));
}
