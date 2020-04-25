/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/24 23:23:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:00:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIT_H
# define FT_BIT_H
# define FT_REQUIRE_TYPE_BOOL
# define FT_REQUIRE_TYPE_SIZE_T
# include <private/ft_include.h>

/*
** Get the bit value from an array of bits at the specified index.
** The given array is supposed to be large enough.
** Returns a positive value if the bit is set to 1, 0 otherwise.
*/
t_bool	ft_bit_at(const void *array, size_t index);

/*
** Map an array of bits from a set of characters.
** Each character in the set is converted to an unsigned character and used as
** an index in the array.
** The given array must have a minimum size of 256 bits (or 32 bytes).
*/
void	ft_bit_map(void *array, size_t size, const char *set);

/*
** Set a bit in an array of bits at the specified index to true.
** The given array is supposed to be large enough.
*/
void	ft_bit_set(void *array, size_t index);

/*
** Returns "true" or "false" depending on the value of the boolean b.
*/
const char	*ft_bit_to_string(t_bool b);

/*
** Set a bit in an array of bits at the specified index to false.
** The given array is supposed to be large enough.
*/
void	ft_bit_unset(void *array, size_t index);

#endif
