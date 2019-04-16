/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 13:43:15 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:58:29 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_atoi() converts the string str into an int. The function will skip
**	the whitespaces before any character and do the convertion untill a
**	non-digital charater is found.
**	For example:
**		"  42" will be convert into 42
**		"  42l21" will also be convert into 42
**
** RETURN VALUES
**	- ft_atoi() returns an int obtained by the convertion of str.
*/

int				ft_atoi(const char *str)
{
	int				nbr;
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
