/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 03:29:19 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 12:46:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_list.h"

char	**ft_strsplit(const char *s, const char *set)
{
	t_list	*l;
	char	**t;

	l = ft_list_split(s, set);
	t = (char **)ft_list_to_array(l);
	ft_list_clear(&l, (t ? NULL : &free));
	return (t);
}
