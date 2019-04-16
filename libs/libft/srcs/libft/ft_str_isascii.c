/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_isascii.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:30:28 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:08:40 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_isascii() function tests if the string str is full of
**	ASCII characters (between 0 and 127 inclusive).
**
** RETURN VALUES
**	- ft_str_isascii() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_isascii(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_isascii(*str++))
			return (0);
	return (1);
}
