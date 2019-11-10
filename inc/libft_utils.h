/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:16:57 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:22:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <stddef.h>

int		ft_atoi(const char *str);

int		ft_atoi_base(char const *str, char const *base);

char	*ft_itoa(int n);

char	*ft_itoa_base(int n, int base);

#endif
