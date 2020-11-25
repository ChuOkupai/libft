/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   failed_alloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 12:02:31 by asoursou          #+#    #+#             */
/*   Updated: 2020/11/25 12:10:37 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <errno.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libft.h>

/*
** This function will be called if ft_new fails.
*/

static void	handler(void)
{
	ft_dprintf(STDERR_FILENO, "error: %s\n", strerror(errno));
	exit(EXIT_FAILURE);
}

int			main(void)
{
	ft_new_setfail(1);
	ft_new_sethook(&handler);
	ft_delete(ft_new(1));
	ft_putendl("Successful allocation!");
	return (0);
}
