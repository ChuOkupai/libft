/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_snprintf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/22 21:26:34 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/22 21:26:34 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdio.h>

int	main(void)
{
	char s[16];

	ft_strcpy(s, "foo");
	ft_printf("%d >%s<\n", ft_snprintf(s, 6, "=%d", 12345), s);
	ft_printf("%d >%s<\n", snprintf(s, 6, "=%d", 12345), s);
	ft_snprintf(NULL, 0, "hello");
	return (0);
}
