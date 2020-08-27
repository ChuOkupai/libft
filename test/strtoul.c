/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strtoul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 11:06:30 by asoursou          #+#    #+#             */
/*   Updated: 2020/08/27 11:07:00 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <libft.h>

static void	test_strtoul(const char *s, int base)
{
	char	*end[2] = { 0 };
	int		err[2];
	t_u64	res[2];

	errno = 0;
	res[0] = ft_strtoul(s, end, 0);
	err[0] = errno;
	errno = 0;
	res[1] = strtoul(s, end + 1, 0);
	err[1] = errno;
	if (end[0] != end[1] || err[0] != err[1] || res[0] != res[1])
		ft_printf("error (libft vs libc):\n|%s|, base = %d\n"
		"res |endptr| (error message)\n%lu |%s| (%s)\n%lu |%s| (%s)\n", s, base,
		res[0], end[0], strerror(err[0]), res[1], end[1], strerror(err[1]));
}

int main(void)
{
	test_strtoul("-9223372036854775809", 10);
	test_strtoul("-9223372036854775808", 10);
	test_strtoul("9223372036854775807", 10);
	test_strtoul("9223372036854775808", 10);
	test_strtoul("18446744073709551616", 10);
	test_strtoul("18446744073709551617", 10);
	return (0);
}
