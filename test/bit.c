/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/20 01:38:07 by asoursou          #+#    #+#             */
/*   Updated: 2020/03/25 00:53:41 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

int	main(void)
{
	t_uchar map[32];

	ft_bzero(map, 32);
	ft_bit_map(map, (t_uchar *)"\xfe\xff");
	ft_print_memory(map, 32);
	return (0);
}
