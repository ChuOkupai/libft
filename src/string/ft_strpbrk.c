/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/29 20:48:19 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/29 20:57:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_string.h"

char	*ft_strpbrk(const char *s, const char *charset)
{
	while (*s && !ft_strchr(charset, *s))
		++s;
	return (*s ? (char*)s : NULL);
}