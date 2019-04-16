/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:14:07 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:20:59 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_isdigit() function tests if the integer c is a decimal-digit
**	character.
**	This includes the following characters (preceded by their decimal values)
**		 48 '0'		 49 '1'		 50 '2'		 51 '3'		 52 '4'
**		 53 '5'		 54 '6'		 55 '7'		 56 '8'		 57 '9'
**
** RETURN VALUES
**	- ft_isdigit() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}
