/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:12:27 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 18:24:11 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H

# include <stddef.h>

char	**ft_split(char const *s, char c);

char	*ft_strcat(char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);

char	*ft_strchrnul(const char *s, int c);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

char	*ft_strdup(const char *s1);

void	ft_striter(char *s, void (*f)(char *));

void	ft_striteri(char *s, void (*f)(unsigned int, char *));

char	*ft_strjoin(char const *s1, char const *s2);

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t	ft_strlen(const char *s);

char	*ft_strmap(char const *s, char (*f)(char));

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char	*ft_strncat(char *s1, const char *s2, size_t n);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

char	*ft_strncpy(char *dst, const char *src, size_t len);

char	*ft_strndup(const char *s1, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *s, int c);

char	*ft_strrev(char *s);

char	*ft_strstr(const char *haystack, const char *needle);

char	*ft_strtrim(char const *s1, char const *set);

char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
