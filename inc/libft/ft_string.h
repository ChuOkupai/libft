/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:12:27 by asoursou          #+#    #+#             */
/*   Updated: 2020/10/31 17:57:40 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STRING_H
# define FT_STRING_H
# define FT_REQUIRE_TYPE_BOOL
# define FT_REQUIRE_TYPE_SIZE_T
# define FT_REQUIRE_TYPE_UNSIGNED
# include "private/ft_include.h"

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
** Returns dst.
*/
char		*ft_stpncpy(char *dst, const char *src, size_t len);

/*
** Append a copy of the null-terminated string s2 to the end
** of the null-terminated string s1, then add a terminating '\0'.
** Returns s1.
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
** Returns dst.
*/
char		*ft_strcpy(char *dst, const char *src);

/*
** Allocates sufficient memory for a copy of the string s1,
** does the copy, and returns a pointer to it.
** Returns NULL on error.
*/
char		*ft_strdup(const char *s);

/*
** Apply a function on each characters of a string.
** The function pointer can use one of the ctype functions,
** for example ft_toupper.
** Returns the string s.
*/
char		*ft_strforeach(char *s, int (*function)(int));

/*
** NULL protected.
** Returns true if the string s is empty.
*/
bool		ft_strisempty(const char *s);

/*
** Allocates and returns a new string,
** result of the concatenation of s1 and s2.
** NULL protected.
** Returns NULL on error.
*/
char		*ft_strjoin(const char *s1, const char *s2);

/*
** Allocates and returns a new string,
** result of the concatenation of s1, s2 and s3.
** NULL protected.
** Returns NULL on error.
*/
char		*ft_strjoin3(const char *s1, const char *s2, const char *s3);

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
** To check whether the string is non-empty, it is faster to use ft_strisempty.
** NULL protected.
*/
size_t		ft_strlen(const char *s);

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
** Allocates and copies at most n characters from the string s1 always
** NULL terminating the copied string.
** Returns NULL on error.
*/
char		*ft_strndup(const char *s1, size_t n);

/*
** Locates the first occurrence of the null-terminated string needle
** in the string haystack, where not more than len characters are searched.
*/
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);

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
** Returns NULL on error.
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
char		*ft_strtrim(const char *s1, const char *charset);

/*
** Iterates over a string while the condition is met.
** Returns a pointer between the beginning and the end of the string,
** depending on the result of the loop.
** The condition function pointer can use one of the ctype functions,
** for example ft_islower.
*/
const char	*ft_strwhile(const char *s, int (*condition)(int));

/*
** Iterates over a string while the condition is not met.
** Returns a pointer between the beginning and the end of the string,
** depending on the result of the loop.
** The condition function pointer can use one of the ctype functions,
** for example ft_islower.
*/
const char	*ft_strwhilenot(const char *s, int (*condition)(int));

/*
** t_string must be initialized with ft_bzero of ft_calloc before use.
*/

typedef struct s_string	t_string;
struct		s_string
{
	char	*buf;
	size_t	size;
	size_t	capacity;
};

/*
** Clears a string object.
** This function must be called before the end of scope of the object.
** Returns the pointer passed as argument.
*/
t_string	*ft_string_clear(t_string *string);

/*
** Copy a string.
** dst must not have been initialized.
** Returns dst.
*/
t_string	*ft_string_copy(t_string *dst, t_string *src);

/*
** Returns the value of the character at the index i, or '\0' if out of bound.
*/
char		ft_string_at(const t_string *string, size_t i);

/*
** Appends a copy of a NULL terminated list of t_string * to the end of the
** string s.
** Returns -1 on error, else 0.
*/
int			ft_string_concat(t_string *s, ...);

/*
** Gets the content of the string object.
** Returns a valid pointer, even if an error has occurred.
*/
const char	*ft_string_cstr(const t_string *string);

/*
** Removes the character at the index i.
** The capacity of the buffer remains unchanged.
*/
void		ft_string_erase_at(t_string *string, size_t i);

/*
** Removes the characters in the range [first, last).
** The capacity of the buffer remains unchanged.
*/
void		ft_string_erase(t_string *string, size_t first, size_t last);

/*
** Inserts the string at the given position i using the given format.
** If index is higher than the string length, str is concatenated.
** Refer to the ft_printf function to know the supported conversions, flags
** and modifiers.
** Returns -1 on error, else 0.
*/
int			ft_string_insert_format(t_string *string, size_t i, const char *fmt,
			...) __attribute__((format(printf,3,4),nonnull(3)));

/*
** Inserts the string str at the given position i.
** If index is higher than the string length, str is concatenated.
** NULL protected.
** Returns -1 on error, else 0.
*/
int			ft_string_insert_str(t_string *string, size_t i, const char *str);

/*
** Inserts character c at the given position i.
** If index is higher than the string length, c is concatenated.
** Returns -1 on error, else 0.
*/
int			ft_string_insert_c(t_string *string, size_t i, char c);

/*
** Inserts the string s at the given position i.
** If index is higher than the string length, str is concatenated.
** Returns -1 on error, else 0.
*/
int			ft_string_insert(t_string *string, size_t i, const t_string *s);

/*
** Gets the length of the string object.
** Returns the number of characters.
*/
size_t		ft_string_length(const t_string *string);

/*
** Appends character c to the end of the string object.
** Returns -1 on error, else 0.
*/
int			ft_string_push_back(t_string *string, char c);

/*
** Appends character c to the beginning of the string object.
** Returns -1 on error, else 0.
*/
int			ft_string_push(t_string *string, char c);

#endif
