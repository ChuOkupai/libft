/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:12:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 22:09:57 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# define FT_REQUIRE_TYPE_SIZE_T
# define FT_REQUIRE_TYPE_UNSIGNED
# include <private/ft_include.h>

/*
** Converts the string str to integer representation.
*/
int			ft_atoi(const char *str);

/*
** Converts the string str to long integer representation.
*/
long		ft_atol(const char *str);

/*
** Converts an int to a string, and returns a pointer to it.
** The pointer must be free.
*/
char		*ft_itoa(int n);

/*
** Converts an int to a string in a base between 2 and 16,
** and returns a pointer to it.
** The pointer must be free.
*/
char		*ft_itoa_base(int n, int base);

/*
** Copy the string src to dst.
** Returns a pointer to the terminating '\0' character of dst.
*/
char		*ft_stpcpy(char *dst, const char *src);

/*
** Copy at most len characters from src into dst. If src is less than
** len characters long, the remainder of dst is filled with '\0' characters.
** Returns a pointer to the terminating '\0' character of dst or dst[n],
** which does not necessarily refer to a valid memory location.
*/
char		*ft_stpncpy(char *dst, const char *src, size_t len);

/*
** Append a copy of the null-terminated string s2 to the end
** of the null-terminated string s1, then add a terminating '\0'.
*/
char		*ft_strcat(char *s1, const char *s2);

/*
** Locates the first occurrence of c (converted to a char) in the string
** pointed to by s. The terminating null character is considered to be part
** of the string; therefore if c is '\0', the functions locate
** the terminating '\0'.
*/
char		*ft_strchr(const char *s, int c);

/*
** Returns a pointer to the first occurrence of c in the string s.
** If c is not found in s, then it returns a pointer to the null byte
** at the end of s.
*/
char		*ft_strchrnul(const char *s, int c);

/*
** Lexicographically comparison the null-terminated strings s1 and s2
*/
int			ft_strcmp(const char *s1, const char *s2);

/*
** Copy the string src to dst.
*/
char		*ft_strcpy(char *dst, const char *src);

/*
** Allocates sufficient memory for a copy of the string s1,
** does the copy, and returns a pointer to it.
*/
char		*ft_strdup(const char *s1);

/*
** Apply a function on each characters of a string.
*/
void		ft_striter(char *s, void (*f)(char *));

/*
** Apply a function on each characters of a string with its index.
*/
void		ft_striteri(char *s, void (*f)(unsigned int, char *));

/*
** Allocates and returns a new string,
** result of the concatenation of s1 and s2.
*/
char		*ft_strjoin(const char *s1, const char *s2);

/*
** Appends string src to the end of dst.
** It will append at most dstsize - strlen(dst) - 1 characters.
*/
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);

/*
** Copies up to dstsize - 1 characters from the string src to dst,
** NUL-terminating the result if dstsize is not 0.
*/
size_t		ft_strlcpy(char *dst, const char *src, size_t dstsize);

/*
** Returns the length of the string s.
*/
size_t		ft_strlen(const char *s);

/*
** Applies the function f to each character of the string s
** to create a new string resulting from successive applications of f.
*/
char		*ft_strmap(const char *s, char (*f)(char));

/*
** Applies the function f to each character of the string s
** to create a new string resulting from successive applications of f.
*/
char		*ft_strmapi(const char *s, char (*f)(unsigned int, char));

/*
** Appends not more than n characters from s2,
** and then adds a terminating '\0'.
*/
char		*ft_strncat(char *s1, const char *s2, size_t n);

/*
** Compares not more than n characters.
*/
int			ft_strncmp(const char *s1, const char *s2, size_t n);

/*
** Copy at most len characters from src into dst. If src is less than
** len characters long, the remainder of dst is filled with '\0' characters.
*/
char		*ft_strncpy(char *dst, const char *src, size_t len);

/*
** Copies at most n characters from the string s1 always NUL terminating
** the copied string.
*/
char		*ft_strndup(const char *s1, size_t n);

/*
** Locates the first occurrence of the null-terminated string needle
** in the string haystack, where not more than len characters are searched.
*/
char		*ft_strnstr(const char *haystack, const char *needle,
				size_t len);

/*
** Locates first occurrence of any character in charset.
** Returns NULL if no characters from charset occur anywhere in s.
*/
char		*ft_strpbrk(const char *s, const char *charset);

/*
** Locates the last occurrence of c (converted to a char) in the string
** pointed to by s. The terminating null character is considered to be part
** of the string; therefore if c is '\0', the functions locate
** the terminating '\0'.
*/
char		*ft_strrchr(const char *s, int c);

/*
** Reverse the string s.
*/
char		*ft_strrev(char *s);

/*
** Locates the first occurrence of any character in the string delim or the
** terminating '\0' character and replaces it with a '\0'.
** The location of the next character after the delimiter character
** (or NULL, if the end of the string was reached) is stored in *stringp.
** The original value of *stringp is returned.
** If *stringp is initially NULL, strsep() returns NULL.
*/
char		*ft_strsep(char **stringp, const char *delim);

/*
** Allocates and returns an array of strings obtained by splitting s
** using all characters from set as delimiters.
** If the given set is empty, all spaces are delimiters by default.
** The array is ended by a NULL pointer.
** If insufficient memory is available, NULL is returned.
*/
char		**ft_strsplit(const char *s, const char *set);

/*
** Locates the first occurrence of the null-terminated string needle
** in the null-terminated string haystack.
*/
char		*ft_strstr(const char *haystack, const char *needle);

/*
** Allocates and returns a substring from the string s.
** The substring begins at index start and is of maximum size len.
** Behavior is undefined is len is greater the the length of string s.
*/
char		*ft_strsub(const char *s, size_t start, size_t len);

/*
** Converts the string in str to an long value.
**
** The string may begin with a certain amout of whitespaces followed
** by a single '-' or '+'.
** Base must be between 2 and 36 inclusive, or be the special value 0.
** If base is zero or 16, the string may then include a "0x" prefix,
** and the number will be read in base 16. Otherwise, a zero base is taken
** as 10 (decimal) unless the next character is '0', in which case it is taken
** as 8 (octal).
** In bases above 10, the letter 'A' in upper or lower case represents 10,
** 'B' represents 11, ..., and 'Z' represents 35.
**
** If endptr is not NULL, it stores the address of the first invalid character
** in *endptr.
*/
long		ft_strtol(const char *str, char **endptr, int base);

/*
** Converts the string in str to an unsigned long value.
**
** The string may begin with a certain amout of whitespaces followed
** by a single '-' or '+'.
** Base must be between 2 and 36 inclusive, or be the special value 0.
** If base is zero or 16, the string may then include a "0x" prefix,
** and the number will be read in base 16. Otherwise, a zero base is taken
** as 10 (decimal) unless the next character is '0', in which case it is taken
** as 8 (octal).
** In bases above 10, the letter 'A' in upper or lower case represents 10,
** 'B' represents 11, ..., and 'Z' represents 35.
**
** If endptr is not NULL, it stores the address of the first invalid character
** in *endptr.
*/
t_u64		ft_strtoul(const char *str, char **endptr, int base);

/*
** Allocates and returns a copy of the string s1, without the characters
** specified in the set at the beginning and the end of the string.
** If the given set is empty, all spaces are delimiters by default.
*/
char		*ft_strtrim(const char *s1, const char *set);

/*
** Iterates over a string while the condition is met.
** Returns a pointer between the beginning and the end of the string,
** depending on the result of the loop.
** The condition function pointer can use on of the ctype functions,
** for example ft_islower.
*/
const char	*ft_strwhile(const char *s, int (*condition)(int));

/*
** Iterates over a string while the condition is not met.
** Returns a pointer between the beginning and the end of the string,
** depending on the result of the loop.
** The condition function pointer can use on of the ctype functions,
** for example ft_islower.
*/
const char	*ft_strwhilenot(const char *s, int (*condition)(int));

#endif
