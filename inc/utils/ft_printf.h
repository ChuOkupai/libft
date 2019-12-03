/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/06 12:41:00 by asoursou          #+#    #+#             */
/*   Updated: 2019/12/03 12:28:18 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stddef.h>
# include <stdint.h>

# define PF_BUFF_SIZE			256
# define PF_CONVERT_BUFF_SIZE	80

typedef enum	e_flag
{
	PF_MINUS = 0x1,
	PF_ZERO = 0x2,
	PF_APOSTROPHE = 0x4,
	PF_HASH = 0x8,
	PF_SPACE = 0x10,
	PF_PLUS = 0x20,
	PF_L = 0x40,
	PF_LL = 0x80,
	PF_H = 0x100,
	PF_HH = 0x200
}				t_flag;

typedef struct	s_format
{
	const char	*s;
	va_list		arg;
	char		buf[PF_BUFF_SIZE];
	char		conv[PF_CONVERT_BUFF_SIZE + 1];
	int			fd;
	int			i;
	t_flag		flags;
	int			dsize;
	int			precision;
	int			width;
	int			err;
	int			size;
}				t_format;

char			*pf_convert(t_format *f, uint64_t n, int base, int lower);

void			pf_flush_buffer(t_format *f);

int64_t			pf_parse_arg(t_format *f);

uint64_t		pf_parse_arg_unsigned(t_format *f);

void			pf_parse_c(t_format *f);

void			pf_parse_d(t_format *f);

void			pf_parse_n(t_format *f);

void			pf_parse_o(t_format *f);

void			pf_parse_p(t_format *f);

void			pf_parse_s(t_format *f);

void			pf_parse_u(t_format *f);

void			pf_parse_x(t_format *f);

void			pf_parse(t_format *f);

void			pf_print(t_format *f, const char *s, const char *hash);

void			pf_putchar(t_format *f, const char c);

void			pf_putpadding(t_format *f);

void			pf_putchar(t_format *f, const char c);

void			pf_putstr(t_format *f, const char *s);

void			pf_putwchar(t_format *f, const wchar_t c);

int				pf_wclen(const wchar_t c);

#endif
