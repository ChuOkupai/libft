/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_int_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/13 01:34:29 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 12:25:27 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "ft_stdio.h"

void	ft_print_int_fd(const void *content, int fd)
{
	ft_putnbr_fd(*((int*)content), fd);
}
