/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_compare_int.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 16:57:56 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 19:26:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_compare_int(const void *a, const void *b)
{
	return (*((int*)a) - *((int*)b));
}