/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_utils.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 16:12:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/02 11:52:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_UTILS_H
# define FT_STRING_UTILS_H
# define FT_REQUIRE_TYPE_BOOL
# include "private/ft_include.h"
# include "ft_string.h"

# define FT_STRING_BUF_INIT_SIZE	16

/*
** Checks if the capacity is sufficiently large to stores size more bytes.
** If not, it reallocates the buffer.
** Returns false on error.
*/
bool	ft_string_check_capacity(t_string *s, size_t size);

#endif
