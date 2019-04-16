/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ppcm.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 13:55:12 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:18:46 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_ppcm() function computes the lowest commun multiple (or "Plus Petit
**	Commun Multiple") of the integers a and b using the Euclide methode.
**
** RETURN VALUES
**	- ft_ppcm() returns the mutiple that has been compute.
*/

int				ft_ppcm(int a, int b)
{
	return ((ft_abs(a * b) / ft_pgcd(a, b)));
}
