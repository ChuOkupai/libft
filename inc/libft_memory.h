/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_memory.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:06:57 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:31:36 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MEMORY_H
# define LIBFT_MEMORY_H

# include <stddef.h>

void	ft_bzero(void *s, size_t n);

void	*ft_calloc(size_t count, size_t size);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_memdel(void **p);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

#endif
