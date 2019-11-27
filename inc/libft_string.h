/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_string.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:12:27 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/27 16:18:58 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_STRING_H
# define LIBFT_STRING_H
# include <stddef.h>

/*
** Append a copy of the null-terminated string s2 to the end
** of the null-terminated string s1, then add a terminating `\0'.
*/
char	*ft_strcat(char *s1, const char *s2);

/*
** Locates the first occurrence of c (converted to a char) in the string
** pointed to by s. The terminating null character is considered to be part
** of the string; therefore if c is `\0', the functions locate
** the terminating `\0'.
*/
char	*ft_strchr(const char *s, int c);

/*
** Returns a pointer to the first occurrence of c in the string s.
** If c is not found in s, then it returns a pointer to the null byte
** at the end of s.
*/
char	*ft_strchrnul(const char *s, int c);

/*
** Lexicographically comparison the null-terminated strings s1 and s2
*/
int		ft_strcmp(const char *s1, const char *s2);

/*
** Copy the string src to dst.
*/
char	*ft_strcpy(char *dst, const char *src);

/*
** Allocates sufficient memory for a copy of the string s1,
** does the copy, and returns a pointer to it.
*/
char	*ft_strdup(const char *s1);

/*
** Apply a function on each characters of a string.
*/
void	ft_striter(char *s, void (*f)(char *));

/*
** Apply a function on each characters of a string with its index.
*/
void	ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** Allocates and returns a new string,
** result of the concatenation of s1 and s2.
*/
char	*ft_strjoin(char const *s1, char const *s2);

/*
** Appends string src to the end of dst.
** It will append at most dstsize - strlen(dst) - 1 characters.
*/
size_t	ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
** Copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0.
*/
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** Returns the length of the string s.
*/
size_t	ft_strlen(const char *s);

/*
** Applies the function f to each character of the string s
** to create a new string resulting from successive applications of f.
*/
char	*ft_strmap(char const *s, char (*f)(char));

/*
** Applies the function f to each character of the string s
** to create a new string resulting from successive applications of f.
*/
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));

/*
** Appends not more than n characters from s2,
** and then adds a terminating `\0'.
*/
char	*ft_strncat(char *s1, const char *s2, size_t n);

/*
** Compares not more than n characters.
*/
int		ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** Copy at most len characters from src into dst. If src is less than
** len characters long, the remainder of dst is filled with `\0' characters.
*/
char	*ft_strncpy(char *dst, const char *src, size_t len);

/*
** Copies at most n characters from the string s1 always NUL terminating
** the copied string.
*/
char	*ft_strndup(const char *s1, size_t n);

/*
** Locates the first occurrence of the null-terminated string needle
** in the string haystack, where not more than len characters are searched
*/
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);

/*
** Locates the last occurrence of c (converted to a char) in the string
** pointed to by s. The terminating null character is considered to be part
** of the string; therefore if c is `\0', the functions locate
** the terminating `\0'.
*/
char	*ft_strrchr(const char *s, int c);

/*
** Reverse the string s.
*/
char	*ft_strrev(char *s);

/*
** Allocates and returns an array of strings obtained by splitting s
** using the character c as a delimiter.
** The array is ended by a NULL pointer.
*/
char	**ft_strsplit(char const *s, char c);

/*
** Locates the first occurrence of the null-terminated string needle
** in the null-terminated string haystack.
*/
char	*ft_strstr(const char *haystack, const char *needle);

/*
** Allocates and returns a substring from the string s.
** The substring begins at index start and is of maximum size len.
*/
char	*ft_strsub(char const *s, unsigned int start, size_t len);

/*
** Allocates and returns a copy of the string s1, without the characters
** specified in the set at the beginning and the end of the string.
*/
char	*ft_strtrim(char const *s1, char const *set);

#endif
