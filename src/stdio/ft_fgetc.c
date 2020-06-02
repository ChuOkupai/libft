/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:31:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 16:46:55 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio_utils.h"

int	ft_fgetc(t_file *f)
{
	unsigned char c;

	if (!ft_fread(&c, sizeof(unsigned char), 1, f))
		return (FT_EOF);
	return (c);
}
