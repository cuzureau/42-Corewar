/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:10:16 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:19:12 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_numlen_base() function computes the length of the absolute value of
**	a decimal digit in a given base. This lenght is expressed in terme of number
**	of characters.
**
** RETURN VALUES
**	- ft_numlen_base() returns the computed value.
*/

size_t			ft_numlen_base(intmax_t n, int base)
{
	size_t			len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}
