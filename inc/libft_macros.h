/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:18:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:23:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H

/*
**		+--------+
**		| MACROS |
**		+--------+
*/

# define ABS(x)		(((x) < 0) ? -(x) : (x))
# define MAX(x, y)	(((x) > (y)) ? (x) : (y))
# define MIN(x, y)	(((x) < (y)) ? (x) : (y))

/*
**		+--------------------+
**		| ANSI ESCAPES CODES |
**		+--------------------+
*/

# define _ANSI_CATRGB(T, R, G, B)	"\x1b["#T";2;"#R";"#G";"#B"m"
# define ANSI_BRGB(R, G, B)			_ANSI_CATRGB(48, R, G, B)
# define ANSI_FRGB(R, G, B)			_ANSI_CATRGB(38, R, G, B)
# define ANSI_RESET()				"\x1b[0m"

#endif