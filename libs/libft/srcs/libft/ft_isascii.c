/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:19:26 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 10:28:58 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_isascii() function tests if the integer c is an ASCII character
**	(between 0 and 127 inclusive).
**
** RETURN VALUES
**	- ft_isalpha() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
