/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isblank.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:32:26 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:18:28 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_isblank() function tests if the string str is full of
**	spaces or tab characters.
**	This includes the following characters (preceded by their decimal values):
**		  9 '\t'		 32 ' '
**
** RETURN VALUES
**	- ft_str_isblank() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_isblank(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isblank(*str++))
			return (0);
	return (1);
}
