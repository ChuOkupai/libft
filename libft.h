/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:25:58 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/14 03:56:22 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

int		ft_isalpha(int c);

int		ft_isdigit(int c);

int		ft_islower(int c);

int		ft_isspace(int c);

int		ft_isupper(int c);

void	*ft_memalloc(size_t size);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

// TODO: Optimiser
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_memdel(void **ap);

// TODO: Optimiser
void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

char	*ft_strcat(char *s1, const char *s2);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s1);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

char	*ft_strncat(char *s1, const char *s2, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strncpy(char *dst, const char *src, size_t len);

char	*ft_strnew(size_t size);

//TODO: améliorer la complexité
char	*ft_strstr(const char *haystack, const char *needle);

#endif
