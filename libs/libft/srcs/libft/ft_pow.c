/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pow.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:32:36 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:18:38 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_pow() function computes n raised to the power exp.
**
** RETURN VALUES
**	- ft_pow() returns the value computed.
*/

int				ft_pow(int n, int exp)
{
	if (exp < 0)
		return (0);
	if (exp == 0)
		return (1);
	return (n * ft_pow(n, exp - 1));
}
