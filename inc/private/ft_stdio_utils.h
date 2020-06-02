/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stdio_utils.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/28 11:22:52 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/02 14:17:38 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_STDIO_UTILS_H
# define FT_STDIO_UTILS_H
# define FT_REQUIRE_TYPE_BOOL
# define FT_REQUIRE_TYPE_SIZE_T
# include "private/ft_include.h"
# include "ft_stdio.h"

# define FT_FILE_BSIZE		128
# define FT_FILE_SAFEBSIZE	4
# define FT_GNL_BSIZE		64

/*
** FT_FOPEN: fd was opened by us
** FT_FALLOC: buffer was allocated by us
** FT_FEOF: end-of-file indicator
** FT_FERROR: error indicator
** FT_FWRITE: write operation (RAW and WAR dependencies)
*/
typedef enum e_fflag	t_fflag;
enum	e_fflag
{
	FT_FOPEN = 0x1,
	FT_FALLOC = 0x2,
	FT_FEOF = 0x4,
	FT_FERROR = 0x8,
	FT_FWRITE = 0x10
};

/*
** fd: file descriptor
** mode: access mode
** flags: structure properties
** buf: buffer for I/O operations
** safe_buf: when malloc fails
** bf: buffering type
** size: buffer size
** start: current index
** left: read/write space left
*/
struct	s_file
{
	int			fd;
	int			mode;
	t_fflag		flags;
	char		*buf;
	char		safe_buf[FT_FILE_SAFEBSIZE];
	size_t		size;
	size_t		start;
	size_t		left;
};

int		ft_check_buffer(t_file *f, t_fflag write);

size_t	ft_fread_internal(t_file *f, void *buf, size_t size);

size_t	ft_fwrite_internal(t_file *f, const void *ptr, size_t size);

#endif
