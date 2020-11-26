/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:02:31 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/26 13:15:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libft.h>

/*
** This function will be called if ft_malloc fails.
*/

static void	handler(void)
{
	ft_dprintf(STDERR_FILENO, "error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

int			main(void)
{
	void *pointer;

	ft_malloc_fail_rate(1.0);
	ft_malloc_hook(&handler);
	pointer = ft_malloc(1);
	ft_putendl("Successful allocation!");
	ft_free(pointer);
	return (0);
}
