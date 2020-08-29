/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:19:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/29 20:30:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"

void	ft_putendl_fd(const char *s, int fd)
{
	(void)(write(fd, s, ft_strlen(s)) + 1);
	(void)(write(fd, "\n", 1) + 1);
}
