/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isxdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:46:14 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:17:30 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_isxdigit() function tests if the string str is full of
**	hexadecimal-digit characters.
**	This includes the following characters (preceded by their decimal values):
**		 48 '0'		 49 '1'		 50 '2'		 51 '3'		 52 '4'
**		 53 '5'		 54 '6'		 55 '7'		 56 '8'		 57 '9'
**		 65 'A'		 66 'B'		 67 'C'		 68 'D'		 69 'E'
**		 70 'F'		 97 'a'		 98 'b'		 99 'c'		100 'd'
**		101 'e'		102 'f'
**
** RETURN VALUES
**	- ft_str_isxdigit() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_isxdigit(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isxdigit(*str++))
			return (0);
	return (1);
}
