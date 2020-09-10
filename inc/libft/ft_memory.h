/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memory.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:06:57 by asoursou          #+#    #+#             */
/*   Updated: 2020/09/10 12:33:32 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MEMORY_H
# define FT_MEMORY_H
# define FT_REQUIRE_TYPE_BOOL
# define FT_REQUIRE_TYPE_SIZE_T
# include "private/ft_include.h"

/*
** Writes n zeroed bytes to s.
*/
void	ft_bzero(void *s, size_t n);

/*
** Allocates enough space for count objects that are size bytes of memory each
** and returns a pointer to the allocated memory.
** The allocated memory is filled with bytes of value zero.
** Returns NULL on error.
*/
void	*ft_calloc(size_t count, size_t size);

/*
** Copies bytes from string src to string dst.
** If the character c occurs in the string src, the copy stops and a pointer
** to the byte after the copy of c in the string dst is returned.
** Otherwise, n bytes are copied, and a NULL pointer is returned.
*/
void	*ft_memccpy(void *dst, const void *src, int c, size_t n);

/*
** Locates the first occurrence of c in s.
*/
void	*ft_memchr(const void *s, int c, size_t n);

/*
** Compares n bytes (each interpreted as unsigned char) of s1 and s2.
*/
int		ft_memcmp(const void *s1, const void *s2, size_t n);

/*
** Copies n bytes from src to dst.
*/
void	*ft_memcpy(void *dst, const void *src, size_t n);

/*
** Free the pointer if not set to NULL.
** Returns NULL.
*/
void	*ft_memdel(void *pointer);

/*
** Free an array and set it to NULL.
** All elements are passed to free().
** Returns NULL.
*/
void	*ft_memdeltab(void ***tab, size_t len);

/*
** Allocates new_size bytes and does the copy of no more than size
** of the src pointer. The remainder is filled with 0 if fill is set to true.
** Returns a pointer to the new allocated memory, or NULL on error.
*/
void	*ft_memdup(const void *src, size_t size, size_t new_size, bool fill);

/*
** Finds the start of the first occurrence of the substring little of length
** little_len in the memory area big of length big_len.
** Returns a pointer to the beginning of the substring, or NULL if the substring
** is not found.
*/
void	*ft_memmem(const void *big, size_t big_len, const void *little,
		size_t little_len);

/*
** Copies len bytes from src to dst without overlapping.
*/
void	*ft_memmove(void *dst, const void *src, size_t len);

/*
** Writes len bytes of value c to b.
*/
void	*ft_memset(void *b, int c, size_t len);

/*
** Returns the size of an array of pointers.
** The array of pointers must have a NULL pointer.
*/
size_t	ft_memsize(void **tab);

/*
** Allocates new_size bytes and does the copy of no more than size of the src
** pointer. The remainder is filled with 0 if fill is set to true.
** If no error occurs, free the src pointer.
** Returns a pointer to the new allocated memory, or NULL on error.
*/
void	*ft_realloc(void *src, size_t size, size_t new_size, bool fill);

#endif
