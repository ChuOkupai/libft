/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/29 18:01:08 by asoursou          #+#    #+#             */
/*   Updated: 2020/05/30 18:18:48 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdio.h>
#include <libft.h>

void write_data()
{
	FILE *f = fopen("file", "w");
	int t[4] = { -782354, 76367499, -990000001, 42000042 };
	fwrite(t, sizeof(int), 4, f);
	fclose(f);
}

void ft_write_data()
{
	t_file *f = ft_fopen("file", "w");
	ft_setvbuf(f, NULL, FT_IONBF, 2);
	int t[4] = { -782354, 76367499, -990000001, 42000042 };
	ft_fwrite(t, sizeof(int), 4, f);
	ft_fclose(f);
}

#define BSIZE 3

void read_data()
{
	char buf[BSIZE] = { 0 };
	int t[4] = { 0 };
	t_file *f = ft_fopen("file", "r");
	ft_setvbuf(f, buf, FT_IOFBF, BSIZE);
	ft_fread(t, sizeof(int), 4, f);
	ft_printf("%d %d %d %d\n", *t, t[1], t[2], t[3]);
	ft_print_memory(buf, BSIZE);
	ft_fclose(f);
}

int	main(void)
{
	ft_write_data();
	read_data();
	return (0);
}
