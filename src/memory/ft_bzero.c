/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:31:01 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 16:45:25 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>

void	ft_bzero(void *s, size_t n)
{
	size_t *t;

	t = s;
	while (n >= 8 * sizeof(size_t))
	{
		t[0] = 0;
		t[1] = 0;
		t[2] = 0;
		t[3] = 0;
		t[4] = 0;
		t[5] = 0;
		t[6] = 0;
		t[7] = 0;
		t += 8;
		n -= 8 * sizeof(size_t);
	}
	while (n >= sizeof(size_t))
	{
		*t++ = 0;
		n -= sizeof(size_t);
	}
	while (n)
		((unsigned char *)t)[--n] = 0;
}
