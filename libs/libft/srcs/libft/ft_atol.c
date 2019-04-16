/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/05/22 14:05:03 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:58:58 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_atol() converts the string str into an long. The function will skip
**	the whitespaces before any character and do the convertion untill a
**	non-digital charater is found.
**	For example:
**		"  42" will be convert into 42
**		"  42l21" will also be convert into 42
**
** RETURN VALUES
**	- ft_atol() returns a long obtained by the convertion of str.
*/

long			ft_atol(const char *str)
{
	long			nbr;
	char			neg;

	nbr = 0;
	neg = FALSE;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		neg = TRUE;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		nbr = ((nbr * 10) + (*str++ - 48));
	if (neg)
		return (-nbr);
	return (nbr);
}
