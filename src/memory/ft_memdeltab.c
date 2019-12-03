/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memdeltab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/03 11:07:31 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/03 11:42:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memdeltab(void ***tab, size_t len)
{
	while (len)
		free((*tab)[--len]);
	free(*tab);
	return (*tab = NULL);
}
