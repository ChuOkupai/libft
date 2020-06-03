/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fgetc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 19:31:25 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/03 11:11:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio_utils.h"
#include "ft_type.h"

int	ft_fgetc(t_file *f)
{
	t_u8 c;

	if (!ft_fread(&c, sizeof(t_u8), 1, f))
		return (FT_EOF);
	return (c);
}
