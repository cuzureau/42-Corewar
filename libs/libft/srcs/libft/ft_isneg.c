/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isneg.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:59:18 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:02:25 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_isneg() function test if the number n is negatif.
**
** RETURN VALUES
**	- ft_isneg() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_isneg(long long n)
{
	return (n < 0);
}
