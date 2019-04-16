/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isdigit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:38:39 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:18:50 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_isdigit() function tests if the string str is full of
**	decimal-digit characters.
**	This includes the following characters (preceded by their decimal values):
**		 48 '0'		 49 '1'		 50 '2'		 51 '3'		 52 '4'
**		 53 '5'		 54 '6'		 55 '7'		 56 '8'		 57 '9'
**
** RETURN VALUES
**	- ft_str_isdigit() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_isdigit(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (1);
}
