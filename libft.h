/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/12 02:25:58 by asoursou          #+#    #+#             */
/*   Updated: 2019/10/07 17:02:56 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

# define ABS(Value) ((Value < 0) ? -Value : Value)

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

void			ft_lstadd_front(t_list **alst, t_list *new);

void			ft_lstclear(t_list **lst, void (*del)(void *));

void			ft_lstdelone(t_list **lst, void (*del)(void *));

t_list			*ft_lstfind(t_list *lst, const void *content,
				int (*cmp)(const void *, const void *));

void			ft_lstinsert(t_list **lst, t_list *new,
				int (*cmp)(const void *, const void *));

void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));

t_list			*ft_lstlast(t_list *lst);

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

t_list			*ft_lstnew(void const *content);

void			ft_lstrev(t_list **lst);

size_t			ft_lstsize(t_list *lst);

void			ft_lstsort(t_list **l, int (*cmp)(const void *, const void *));

void			*ft_memccpy(void *dst, const void *src, int c, size_t n);

void			*ft_memchr(const void *s, int c, size_t n);

int				ft_memcmp(const void *s1, const void *s2, size_t n);

void			*ft_memcpy(void *dst, const void *src, size_t n);

void			ft_memdel(void **ap);

void			*ft_memmove(void *dst, const void *src, size_t len);

void			*ft_memset(void *b, int c, size_t len);

void			*ft_print_memory(const void *s, size_t n);

void			ft_putchar(char c);

void			ft_putchar_fd(char c, int fd);

void			ft_putendl(char const *s);

void			ft_putendl_fd(char const *s, int fd);

void			ft_putnbr(int n);

void			ft_putnbr_base(int n, char const *base);

void			ft_putnbr_base_fd(int n, char const *base, int fd);

void			ft_putnbr_fd(int n, int fd);

void			ft_putstr(char const *s);

void			ft_putstr_fd(char const *s, int fd);

char			*ft_strcat(char *s1, const char *s2);

char			*ft_strchr(const char *s, int c);

char			*ft_strchrnul(const char *s, int c);

void			ft_strclr(char *s);

int				ft_strcmp(const char *s1, const char *s2);

char			*ft_strcpy(char *dst, const char *src);

void			ft_strdel(char **as);

char			*ft_strdup(const char *s1);

int				ft_strequ(char const *s1, char const *s2);

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

int				ft_strnequ(char const *s1, char const *s2, size_t n);

char			*ft_strnew(size_t size);

char			*ft_strnstr(const char *haystack, const char *needle,
				size_t len);

char			*ft_strrchr(const char *s, int c);

char			**ft_strsplit(char const *s, char c);

char			*ft_strstr(const char *haystack, const char *needle);

char			*ft_strtrim(char const *s1, char const *set);

char			*ft_substr(char const *s, unsigned int start, size_t len);

int				ft_tolower(int c);

int				ft_toupper(int c);

#endif
