/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 18:21:07 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/30 18:45:39 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_isspace() function tests if the integer c is a white-space
**	character.
**	This includes the following characters (preceded by their decimal values):
**		  9 '\t'	 10 '\n'	 11 '\v'	 12 '\f'	 13 '\r'
**		 32 ' '
**
** RETURN VALUES
**	- ft_isspace() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' || \
			c == '\f' || c == '\r' || c == ' ');
}
