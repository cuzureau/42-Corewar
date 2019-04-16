/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ispunct.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:42:46 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:19:55 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_ispunct() function tests if the string str is full of
**	punctuation characters, that exclude the alphanumeric characters
**	and space (' ').
**	This includes the following characters (preceded by their decimal values):
**		 33 '!'		 34 '"'		 35 '#'		 36 '$'		 37 '%'
**		 38 '&'		 39 '''		 40 '('		 41 ')'		 42 '*'
**		 43 '+'		 44 ','		 45 '-'		 46 '.'		 47 '/'
**		 58 ':'		 59 ';'		 60 '<'		 61 '='		 62 '>'
**		 63 '?'		 64 '@'		 91 '['		 92 '\'		 93 ']'
**		 94 '^'		 95 '_'		 96 '`'		123 '{'		124 '|'
**		125 '}'		126 '~'
**
** RETURN VALUES
**	- ft_str_ispunct() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_ispunct(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_ispunct(*str++))
			return (0);
	return (1);
}
