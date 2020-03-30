/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_bit.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:23:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 13:37:45 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_BIT_H
# define LIBFT_BIT_H
# include <stddef.h>

/*
** Get the bit value from an array of bits at the specified index.
** The given array is supposed to be large enough.
** Returns a positive value if the bit is set to 1, 0 otherwise.
*/
unsigned char	ft_bit_at(const void *array, size_t index);

/*
** Map an array of bits from a set of characters.
** Each character in the set is converted to an unsigned character and used as
** an index in the array.
** The given array must have a minimum size of 256 bits (or 32 bytes).
*/
void			ft_bit_map(void *array, size_t size, const char *set);

/*
** Set a bit in an array of bits at the specified index to true.
** The given array is supposed to be large enough.
*/
void			ft_bit_set(void *array, size_t index);

/*
** Set a bit in an array of bits at the specified index to false.
** The given array is supposed to be large enough.
*/
void			ft_bit_unset(void *array, size_t index);

#endif
