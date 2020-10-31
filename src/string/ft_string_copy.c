/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 16:59:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 17:17:32 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"
#include "ft_string.h"

t_string	*ft_string_copy(t_string *dst, t_string *src)
{
	ft_bzero(dst, sizeof(dst));
	ft_string_insert_str(dst, 0, ft_string_cstr(src));
	return (dst);
}
