/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_nextprime.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 12:38:59 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:19:02 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_nextprime() function searches the next prime number that comes
**	after the integer n, even if n is already prime.
**
** RETURN VALUES
**	- ft_nextprime() return the computed value.
*/

int				ft_nextprime(int n)
{
	if (ft_isprime(n))
		n++;
	while (!ft_isprime(n))
		n++;
	return (n);
}
