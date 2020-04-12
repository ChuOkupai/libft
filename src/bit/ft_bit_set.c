/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit_set.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:56:50 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/12 18:24:59 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "ft_bit.h"

void	ft_bit_set(void *array, size_t index)
{
	((uint8_t *)array)[index / 8] |= 0x80 >> index % 8;
}
