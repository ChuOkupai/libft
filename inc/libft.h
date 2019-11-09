/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:25:58 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/09 13:33:35 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define ABS(x)		(((x) < 0) ? -(x) : (x))
# define MAX(x, y)	(((x) > (y)) ? (x) : (y))
# define MIN(x, y)	(((x) < (y)) ? (x) : (y))

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				ft_atoi(const char *str);

int				ft_atoi_base(char const *str, char const *base);

void			ft_bzero(void *s, size_t n);

void			*ft_calloc(size_t count, size_t size);

int				ft_isalnum(int c);

int				ft_isalpha(int c);

int				ft_isascii(int c);

int				ft_isblank(int c);

int				ft_iscntrl(int c);

int				ft_isdigit(int c);

int				ft_isgraph(int c);

int				ft_islower(int c);

int				ft_isprint(int c);

int				ft_ispunct(int c);

int				ft_isspace(int c);

int				ft_isupper(int c);

int				ft_isxdigit(int c);

char			*ft_itoa(int n);

char			*ft_itoa_base(int n, int base);

void			ft_list_add(t_list **l, t_list *elem);

t_list			*ft_list_at(t_list *l, size_t index);

void			ft_list_clear(t_list **l, void (*del)(void *));

t_list			*ft_list_find(t_list *l, const void *reference,
				int (*cmp)(const void *, const void *));

void			ft_list_foreach(t_list *l, void (*f)(void *));

void			ft_list_insert(t_list **l, t_list *elem,
				int (*cmp)(const void *, const void *));

t_list			*ft_list_last(t_list *l);

t_list			*ft_list_new(void *content);

void			ft_list_pop(t_list **l, void (*del)(void *));

void			ft_list_push(t_list **l, t_list *elem);

void			ft_list_remove_if(t_list **l, const void *reference,
				int (*cmp)(const void *, const void *), void (*del)(void *));

void			ft_list_rev(t_list **l);

size_t			ft_list_size(t_list *l);

void			ft_list_sort(t_list **l,
				int (*cmp)(const void *, const void *));

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			ft_memdel(void **ap);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			*ft_print_memory(const void *s, size_t n);

void			ft_putchar(int c);

void			ft_putchar_fd(int c, int fd);

void			ft_putendl(char *s);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr(int n);

void			ft_putnbr_base(int n, char const *base);

void			ft_putnbr_base_fd(int n, char const *base, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr(char *s);

void			ft_putstr_fd(char *s, int fd);

char			**ft_split(char const *s, char c);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strchr(const char *s, int c);

char			*ft_strchrnul(const char *s, int c);

void			ft_strclr(char *s);

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcpy(char *dst, const char *src);

char			*ft_strdup(const char *s1);

void			ft_striter(char *s, void (*f)(char *));

void			ft_striteri(char *s, void (*f)(unsigned int, char *));

char			*ft_strjoin(char const *s1, char const *s2);

size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);

size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);

size_t			ft_strlen(const char *s);

char			*ft_strmap(char const *s, char (*f)(char));

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

char			*ft_strncat(char *s1, const char *s2, size_t n);

int				ft_strncmp(const char *s1, const char *s2, size_t n);

char			*ft_strncpy(char *dst, const char *src, size_t len);

char			*ft_strndup(const char *s1, size_t n);

char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);

char			*ft_strrchr(const char *s, int c);

char			*ft_strrev(char *s);

char			*ft_strstr(const char *haystack, const char *needle);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_tolower(int c);

int				ft_toupper(int c);

#endif
