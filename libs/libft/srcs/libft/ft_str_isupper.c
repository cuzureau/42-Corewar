/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isupper.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:02:33 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:17:06 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_isupper() function tests if the string str is full of
**	upper-case letters.
**	This includes the following characters (preceded by their decimal values):
**		 65 'A'		 66 'B'		 67 'C'		 68 'D'		 69 'E'
**		 70 'F'		 71 'G'		 72 'H'		 73 'I'		 74 'J'
**		 75 'K'		 76 'L'		 77 'M'		 78 'N'		 79 'O'
**		 80 'P'		 81 'Q'		 82 'R'		 83 'S'		 84 'T'
**		 85 'U'		 86 'V'		 87 'W'		 88 'X'		 89 'Y'
**		 90 'Z'
**
** RETURN VALUES
**	- ft_str_isupper() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_isupper(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isupper(*str++))
			return (0);
	return (1);
}
