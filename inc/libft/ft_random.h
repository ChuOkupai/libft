/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_random.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 12:43:15 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/27 13:39:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_RANDOM_H
# define FT_RANDOM_H
# define FT_REQUIRE_TYPE_UNSIGNED
# include "private/ft_include.h"

/*
** ft_random implements the Xoroshiro256** algorithm.
** Warning: This algorithm is not considered as a cryptographically secure PRNG!
** This implementation is based on the implementation of David Blackman and
** Sebastiano Vigna.
*/

# define XORSHIRO_SIZE	4
# if XORSHIRO_SIZE != 4
#  error "Illegal value set for variable XORSHIRO_SIZE"
# endif

/*
** Returns the next pseudorandom uniformly distributed unsigned long value.
** This function use a Xoroshiro256** generator internally.
** ft_seed must be called before any calls to ft_rand to avoid undefined
** behavior.
*/
t_u64	ft_rand(void);

/*
** Sets the seed used by the generator.
** The seed value can be the result of time(NULL) or getpid().
*/
void	ft_seed(t_u64 seed);

/*
** Initialize a Xoroshiro256** generator with the given seed.
** The generator must have a minimum size of XORSHIRO_SIZE.
** This function use a splitmix64 generator internally.
*/
void	ft_xorshiro256ss_init(t_u64 *generator, t_u64 seed);

/*
** Returns the next pseudorandom uniformly distributed unsigned long value using
** the given Xoroshiro256** generator.
** The states variable must have a minimum size of XORSHIRO_SIZE.
*/
t_u64	ft_xorshiro256ss_next(t_u64 *generator);

#endif
