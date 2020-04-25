/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strwhilenot.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 19:34:35 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 19:34:42 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

const char	*ft_strwhilenot(const char *s, int (*condition)(int))
{
	while (*s && !condition(*s))
		++s;
	return (s);
}
