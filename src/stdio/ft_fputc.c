/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fputc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/30 19:37:23 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 16:41:33 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio_utils.h"
#include "ft_type.h"

int	ft_fputc(int c, t_file *f)
{
	t_u8 ch;

	ch = (t_u8)c;
	if (!ft_fwrite(&ch, sizeof(t_u8), 1, f))
		return (FT_EOF);
	return (ch);
}
