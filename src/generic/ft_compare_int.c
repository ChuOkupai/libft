/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:57:56 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 16:58:43 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_compare_int(const void *reference, const void *content)
{
	return (*((int*)reference) - *((int*)content));
}
