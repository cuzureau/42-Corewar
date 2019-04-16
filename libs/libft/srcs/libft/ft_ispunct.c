/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ispunct.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:58:15 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:22:05 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_ispunct() function tests if the integer c is a punctuation
**	character, that exclude the alphanumeric characters and space (' ').
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
**	- ft_ispunct() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_ispunct(int c)
{
	return (ft_isgraph(c) && !ft_isalnum(c));
}
