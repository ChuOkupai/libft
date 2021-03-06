/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/19 19:10:47 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 19:36:15 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

void	ft_putnstr_fd(const char *s, size_t n, int fd)
{
	size_t max;

	if ((max = ft_strlen(s)) > n)
		max = n;
	(void)(write(fd, s, max) + 1);
}
