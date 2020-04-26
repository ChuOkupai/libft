/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stpcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/09 04:46:22 by asoursou          #+#    #+#             */
/*   Updated: 2020/02/09 04:47:39 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_stpcpy(char *dst, const char *src)
{
	while ((*dst = *src++))
		dst++;
	return (dst);
}