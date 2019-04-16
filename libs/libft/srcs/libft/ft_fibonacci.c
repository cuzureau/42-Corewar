/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:51:28 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:00:25 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_fibonacci() computes the n-th value of the Fibonacci sequence.
**
** RETURN VALUES
**	ft_fibonacci() returns the n-th value of Fibonacci.
*/

int				ft_fibonacci(int n)
{
	if (n < 0)
		return (ERROR);
	if (n == 0)
		return (0);
	if (n == 1)
		return (n);
	return (ft_fibonacci(n - 1) + ft_fibonacci(n - 2));
}
