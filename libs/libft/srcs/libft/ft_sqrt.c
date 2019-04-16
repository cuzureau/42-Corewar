/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 11:07:08 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:14:20 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_sqrt() function compute the floored square root of n, if n is
**	greater of equal to zero.
**
** RETURN VALUES
**	- ft_sqrt() returns 0 if n is less than 0 and the largest integral value
**	less than the float square root of x.
*/

int				ft_sqrt(int n)
{
	int				ret;
	int				one;

	if (n < 0)
		return (FALSE);
	ret = 0;
	one = 1 << 30;
	while (one > n)
		one >>= 2;
	while (one != 0)
	{
		if (n >= ret + one)
		{
			n -= ret + one;
			ret += 2 * one;
		}
		ret >>= 1;
		one >>= 2;
	}
	return (ret);
}
