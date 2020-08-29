/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:35:38 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/29 20:30:50 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stdio.h"

void	ft_putnbr_base(int n, const char *base)
{
	ft_putnbr_base_fd(n, base, STDOUT_FILENO);
}
