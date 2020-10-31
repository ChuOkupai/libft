/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string_insert.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 17:22:11 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 17:23:31 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

int	ft_string_insert(t_string *s, size_t i, const t_string *s2)
{
	return (ft_string_insert_str(s, i, ft_string_cstr(s2)));
}
