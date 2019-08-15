/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:25:58 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/15 05:52:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

int		ft_atoi(const char *str);

void	ft_bzero(void *s, size_t n);

int		ft_isalnum(int c);

int		ft_isalpha(int c);

int		ft_isascii(int c);

int		ft_isblank(int c);

int		ft_isdigit(int c);

int		ft_islower(int c);

int		ft_isprint(int c);

int		ft_isspace(int c);

int		ft_isupper(int c);

char	*ft_itoa(int n);

void	*ft_memalloc(size_t size);

void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

// TODO: Optimiser
void	*ft_memchr(const void *s, int c, size_t n);

int		ft_memcmp(const void *s1, const void *s2, size_t n);

void	*ft_memcpy(void *dst, const void *src, size_t n);

void	ft_memdel(void **ap);

void	*ft_memmove(void *dst, const void *src, size_t len);

void	*ft_memset(void *b, int c, size_t len);

void	ft_putchar(char c);

void	ft_putchar_fd(char c, int fd);

void	ft_putendl(char const *s);

void	ft_putendl_fd(char const *s, int fd);

void	ft_putnbr(int n);

void	ft_putnbr_fd(int n, int fd);

void	ft_putstr(char const *s);

void	ft_putstr_fd(char const *s, int fd);

char	*ft_strcat(char *s1, const char *s2);

char	*ft_strchr(const char *s, int c);

void	ft_strclr(char *s);

int		ft_strcmp(const char *s1, const char *s2);

char	*ft_strcpy(char *dst, const char *src);

void	ft_strdel(char **as);

char	*ft_strdup(const char *s1);

int		ft_strequ(char const *s1, char const *s2);

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

int		ft_strnequ(char const *s1, char const *s2, size_t n);

char	*ft_strnew(size_t size);

//TODO: Améliorer la complexité
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

char	*ft_strrchr(const char *s, int c);

char	**ft_strsplit(char const *s, char c);

//TODO: Améliorer la complexité
char	*ft_strstr(const char *haystack, const char *needle);

char	*ft_strsub(char const *s, unsigned int start, size_t len);

char	*ft_strtrim(char const *s);

int		ft_tolower(int c);

int		ft_toupper(int c);

#endif
