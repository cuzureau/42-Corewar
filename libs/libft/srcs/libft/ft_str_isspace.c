/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isspace.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:44:36 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:16:40 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_isspace() function tests if the string str is full of
**	white-space characters.
**	This includes the following characters (preceded by their decimal values):
**		  9 '\t'	 10 '\n'	 11 '\v'	 12 '\f'	 13 '\r'
**		 32 ' '
**
** RETURN VALUES
**	- ft_str_isspace() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_isspace(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isspace(*str++))
			return (0);
	return (1);
}
