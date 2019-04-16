/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:50:19 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:19:06 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_numlen() function computes the length of the absolute value of a
**	decimal digit. This lenght is expressed in terme of number of digits.
**
** RETURN VALUES
**	- ft_numlen() returns the computed value.
*/

size_t			ft_numlen(intmax_t n)
{
	return (ft_numlen_base(n, 10));
}
