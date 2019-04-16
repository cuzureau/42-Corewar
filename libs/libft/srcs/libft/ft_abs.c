/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:57:05 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:57:48 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_abs() function computes the absolute value of the number n.
**	For example:
**		the absolute value of -42 is 42.
**		the absolute value of 42 is 42.
**
** RETURN VALUES
**	- ft_abs() return the absolute value of n.
*/

long long		ft_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}
