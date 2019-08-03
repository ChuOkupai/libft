/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 22:57:54 by asoursou          #+#    #+#             */
/*   Updated: 2019/08/03 23:54:07 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

int				ft_atoi_base(char *str, char *base);

int				ft_atoi(char *str);

int				ft_atoi_base(char *str, char *base);

void			*ft_print_memory(void *addr, unsigned int size);

void			ft_putchar(char c);

void			ft_putnbr(int nb);

void			ft_putstr(char *str);

void			ft_putstr_non_printable(char *str);

void			ft_sort_int_tab(int *tab, int size);

char			*ft_strcat(char *dest, char *src);

int				ft_strcmp(char *s1, char *s2);

char			*ft_strcpy(char *dest, char *src);

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);

char			*ft_strncat(char *dest, char *src, unsigned int nb);

int				ft_strncmp(char *s1, char *s2, unsigned int n);

char			*ft_strncpy(char *dest, char *src, unsigned int n);

int				ft_strlen(char *str);

char			*ft_strstr(char *str, char *to_find);

#endif
