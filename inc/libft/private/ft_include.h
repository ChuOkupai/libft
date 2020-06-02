/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_include.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/25 13:03:14 by asoursou          #+#    #+#             */
/*   Updated: 2020/06/01 20:47:47 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_INCLUDE_H
# define FT_INCLUDE_H

/*
** This header is only intended to check the inclusion of certain system
** headers, in order to include functions or types which depend on them.
** It should not be used directly in your programs.
*/

# if defined FT_REQUIRE_TYPE_SIZE_T
#  undef FT_REQUIRE_TYPE_SIZE_T
#  include <stddef.h>
# endif

# if defined FT_REQUIRE_TYPE_SSIZE_T
#  undef FT_REQUIRE_TYPE_SSIZE_T
#  include <sys/types.h>
# endif

# if defined FT_NEED_TYPE_VA_LIST
#  undef FT_NEED_TYPE_VA_LIST
#  if defined __GNUC_VA_LIST || defined _BSD_VA_LIST || defined VA_LIST
#   define FT_TYPE_VA_LIST
#  elif defined VA_LIST_ || defined VA_LIST__ || defined _VA_LIST
#   define FT_TYPE_VA_LIST
#  elif defined _VA_LIST_ || defined _VA_LIST__ || defined __VA_LIST
#   define FT_TYPE_VA_LIST
#  elif defined __VA_LIST_ ||defined __VA_LIST__
#   define FT_TYPE_VA_LIST
#  endif
# endif

# ifdef FT_REQUIRE_TYPE_BOOL
#  undef FT_REQUIRE_TYPE_BOOL
#  include <stdbool.h>

typedef bool	t_bool;
# endif

# ifdef FT_REQUIRE_TYPE_SIGNED
#  undef FT_REQUIRE_TYPE_SIGNED

typedef char		t_s8;
typedef short		t_s16;
typedef int			t_s32;
typedef long		t_s64;
typedef long long	t_s128;
# endif

# ifdef FT_REQUIRE_TYPE_UNSIGNED
#  undef FT_REQUIRE_TYPE_UNSIGNED

typedef unsigned char		t_u8;
typedef unsigned short		t_u16;
typedef unsigned int		t_u32;
typedef unsigned long		t_u64;
typedef unsigned long long	t_u128;

typedef t_u8	t_byte;
typedef t_u16	t_word;
typedef t_u32	t_dword;
typedef t_u64	t_qword;
# endif

# ifdef FT_REQUIRE_TYPE_GENERIC
#  undef FT_REQUIRE_TYPE_GENERIC

/*
** Generic function pointer taking a pointer as an argument. ¯\_(ツ)_/¯
*/
typedef void	(*t_gfunction)(void *content);

/*
** Generic comparison function pointer.
*/
typedef int		(*t_gcompare)(const void *reference, const void *content);

/*
** Generic display function pointer.
*/
typedef void	(*t_gprint)(const void *content);

/*
** Generic display to file descriptor function pointer.
*/
typedef void	(*t_gprint_fd)(const void *content, int fd);

# endif

# undef FT_INCLUDE_H
#endif
