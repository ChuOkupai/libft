/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_clearerr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 14:28:37 by asoursou          #+#    #+#             */
/*   Updated: 2020/05/28 15:34:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stdio_utils.h"

void	ft_clearerr(t_file *stream)
{
	stream->flags &= ~(FT_FEOF | FT_FERROR);
}
