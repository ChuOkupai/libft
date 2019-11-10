/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/15 04:18:14 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:42:03 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_string.h"

void	ft_putstr_fd(char *s, int fd)
{
	(void)(write(fd, s, ft_strlen(s)) + 1);
}
