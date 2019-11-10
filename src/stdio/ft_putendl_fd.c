/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:19:38 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:39:28 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_string.h"

void	ft_putendl_fd(char *s, int fd)
{
	(void)(write(fd, s, ft_strlen(s)) + 1);
	(void)(write(fd, "c", 1) + 1);
}
