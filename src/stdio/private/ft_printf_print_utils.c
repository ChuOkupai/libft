/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_print_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 10:13:05 by asoursou          #+#    #+#             */
/*   Updated: 2020/01/23 13:58:54 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_printf.h"
#include "libft_memory.h"

void	pf_flush_buffer(t_format *f)
{
	if (f->pflags & PF_ERROR)
		return ;
	if (f->pflags & PF_USE_STR)
	{
		if (f->pflags & PF_USE_LEFT)
		{
			if (!f->left || f->left - 1 < (size_t)f->i)
			{
				f->i = f->left - (f->left > 0);
				f->left = (f->left > 0);
			}
			else
				f->left -= f->i;
		}
		f->str = ft_memcpy(f->str, f->buf, f->i) + f->i;
	}
	else if (write(f->fd, f->buf, f->i) < 0)
		f->pflags |= PF_ERROR;
	f->i = 0;
}

void	pf_print(t_format *f, const char *s, const char *hash)
{
	if (!(f->flags & PF_MINUS))
		pf_putpadding(f);
	if (f->flags & PF_HASH)
		pf_putstr(f, hash);
	while (f->precision--)
		pf_putchar(f, '0');
	if (f->dsize)
		pf_putstr(f, s);
	if ((f->flags & PF_MINUS))
		pf_putpadding(f);
	++f->s;
}

void	pf_putchar(t_format *f, const char c)
{
	++f->size;
	f->buf[f->i++] = c;
	if (f->i == PF_BUFF_SIZE)
		pf_flush_buffer(f);
}

void	pf_putpadding(t_format *f)
{
	char c;

	c = (f->flags & PF_ZERO) ? '0' : ' ';
	while (f->width--)
		pf_putchar(f, c);
}

void	pf_putstr(t_format *f, const char *s)
{
	while (*s)
		pf_putchar(f, *s++);
}
