/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:06:00 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:21:34 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_islower() function tests if the integer c is a lower-case letter.
**	This includes the following characters (preceded by their decimal values):
**		 97 'a'		 98 'b'		 99 'c'		100 'd'		101 'e'
**		102 'f'		103 'g'		104 'h'		105 'i'		106 'j'
**		107 'k'		108 'l'		109 'm'		110 'n'		111 'o'
**		112 'p'		113 'q'		114 'r'		115 's'		116 't'
**		117 'u'		118 'v'		119 'w'		120 'x'		121 'y'
**		122 'z'
**
** RETURN VALUES
**	- ft_islower() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_islower(int c)
{
	return (c >= 'a' && c <= 'z');
}
