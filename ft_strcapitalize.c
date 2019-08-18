/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:23:52 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/18 21:10:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcapitalize(char *str)
{
	char	*s;

	s = str;
	while ((*s = ft_toupper(*s)))
		while (ft_isalnum(*s++) && *s)
			*s = ft_tolower(*s);
	return (str);
}
