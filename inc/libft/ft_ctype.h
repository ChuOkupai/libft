/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ctype.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asoursou <asoursou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/10 18:04:55 by asoursou          #+#    #+#             */
/*   Updated: 2020/04/25 17:48:20 by asoursou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_CTYPE_H
# define FT_CTYPE_H

/*
** Checks if the character is alphanumeric.
*/
int	ft_isalnum(int c);

/*
** Checks if the character is alphabetic.
*/
int	ft_isalpha(int c);

/*
** Checks if the character is ASCII.
*/
int	ft_isascii(int c);

/*
** Checks if the character is space or tabulation.
*/
int	ft_isblank(int c);

/*
** Checks if the character is control character.
*/
int	ft_iscntrl(int c);

/*
** Checks if the character is decimal digit.
*/
int	ft_isdigit(int c);

/*
** Checks if the character has graphical representation.
*/
int	ft_isgraph(int c);

/*
** Checks if the character is lowercase letter.
*/
int	ft_islower(int c);

/*
** Checks if the character is printable.
*/
int	ft_isprint(int c);

/*
** Checks if the character is a punctuation.
*/
int	ft_ispunct(int c);

/*
** Checks if the character is white-space.
*/
int	ft_isspace(int c);

/*
** Checks if the character is an uppercase letter.
*/
int	ft_isupper(int c);

/*
** Checks if the character is a hexadecimal digit.
*/
int	ft_isxdigit(int c);

/*
** Converts uppercase letters to lowercase.
*/
int	ft_tolower(int c);

/*
** Converts non printable chracter to printable equivalent if possible.
** Ex: ft_toprint('\n') returns 'n'
*/
int	ft_toprint(int c);

/*
** Converts lowercase letters to uppercase.
*/
int	ft_toupper(int c);

#endif
