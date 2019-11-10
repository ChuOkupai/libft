/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:13:05 by asoursou          #+#    #+#             */
/*   Updated: 2019/11/10 19:02:21 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "utils/ft_printf.h"

void	pf_flush_buffer(t_format *f)
{
	if (!f->err && write(f->fd, f->buf, f->i) < 0)
		f->err = -1;
	f->i = 0;
}

void	pf_print(t_format *f, const char *s, const char *hash)
{
	if (!FLAG(PF_MINUS))
		pf_putpadding(f);
	if (FLAG(PF_HASH))
		pf_putstr(f, hash);
	while (f->precision--)
		pf_putchar(f, '0');
	if (f->dsize)
		pf_putstr(f, s);
	if (FLAG(PF_MINUS))
		pf_putpadding(f);
	f->s++;
}

void	pf_putchar(t_format *f, const char c)
{
	f->size++;
	f->buf[f->i++] = c;
	if (f->i == PF_BUFF_SIZE)
		pf_flush_buffer(f);
}

void	pf_putpadding(t_format *f)
{
	char c;

	c = FLAG(PF_ZERO) ? '0' : ' ';
	while (f->width--)
		pf_putchar(f, c);
}

void	pf_putstr(t_format *f, const char *s)
{
	while (*s)
		pf_putchar(f, *s++);
}
