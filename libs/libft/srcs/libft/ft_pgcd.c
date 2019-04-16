/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pgcd.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/30 10:53:54 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:18:26 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_pgcd() function computes the higest common factor (or "Plus Grand
**	Commun Diviseur") of the integers a and b using the Euclide methode.
**
** RETURN VALUES
**	- ft_pgcd() returns the factor that has been compute.
*/

int				ft_pgcd(int a, int b)
{
	if (!(a % b))
		return (b);
	return (ft_pgcd(b, a % b));
}
