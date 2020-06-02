/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputs.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 19:53:43 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 16:41:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio_utils.h"
#include "ft_string.h"

int	ft_fputs(const char *s, t_file *f)
{
	size_t n;

	if (!(n = ft_fwrite(s, sizeof(char), ft_strlen(s), f)))
		return (FT_EOF);
	return (n);
}
