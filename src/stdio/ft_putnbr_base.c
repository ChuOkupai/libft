/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/04 02:35:38 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:40:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft_stdio.h"

void	ft_putnbr_base(int n, char const *base)
{
	ft_putnbr_base_fd(n, base, STDOUT_FILENO);
}
