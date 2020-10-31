/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_pointer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:19:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/29 14:20:46 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_generic.h"

void	ft_print_pointer(const void *pointer)
{
	ft_print_pointer_fd(pointer, STDOUT_FILENO);
}
