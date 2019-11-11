/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_macros.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:18:29 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/11 13:05:16 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MACROS_H
# define LIBFT_MACROS_H

/*
** +--------+
** | MACROS |
** +--------+
*/

/*
** Returns the absolute value of an integer.
** Not compatible with floating points datatypes, use FABS instead.
*/
# define ABS(x) (((x) < 0) ? -(x) : (x))

/*
** Returns the absolute value of a floating point.
** Not compatible with integers datatypes, use ABS instead.
*/
# define FABS(x) (((x) < 0.0) ? -(x) : (x))

/*
** Returns the maximum between x and y.
*/
# define MAX(x, y) (((x) > (y)) ? (x) : (y))

/*
** Returns the minimum between x and y.
*/
# define MIN(x, y) (((x) < (y)) ? (x) : (y))

/*
** +--------------------+
** | ANSI ESCAPES CODES |
** +--------------------+
*/

/*
** Utility macro. Do not use.
*/
# define _ANSI_CATRGB(T, R, G, B) "\x1b["#T";2;"#R";"#G";"#B"m"

/*
** Changes the background text color.
*/
# define ANSI_BRGB(R, G, B) _ANSI_CATRGB(48, R, G, B)

/*
** Changes the foreground text color.
*/
# define ANSI_FRGB(R, G, B) _ANSI_CATRGB(38, R, G, B)

/*
** Reset every text options.
*/
# define ANSI_RESET() "\x1b[0m"

#endif
