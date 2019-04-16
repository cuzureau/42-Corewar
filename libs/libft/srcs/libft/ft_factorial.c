/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_factorial.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:32:55 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:59:58 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_factorial() computes the factorial value of the integer n.
**	For example:
**		3! = 3 * 2 * 1 = 6
**		5! = 5 * 4 * 3 * 2 * 1 = 120
**
** RETURN VALUES
**	- ft_factorial() returns n!. If n is lower than 0 or greater than 12, the
**	function return 0.
*/

int				ft_factorial(int n)
{
	if (n > 12 || n < 0)
		return (FALSE);
	if (n == 1)
		return (n);
	return (n * ft_factorial(n - 1));
}
