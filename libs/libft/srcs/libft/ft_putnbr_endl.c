/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_endl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/05 15:21:49 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:17:02 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putnbr_endl() function attempts to write the number n converted
**	into succecive characters followed by a '\n' character on the standard
**	output, a.k.a. stdout.
**
** RETURN VALUES
**	- ft_putnbr_endl() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

static void		ft_outnbr_endl(int n)
{
	unsigned int	i;

	if (n < 0)
		ft_putchar('-');
	i = ft_abs(n);
	if (i >= 10)
	{
		ft_putnbr(i / 10);
		ft_putnbr(i % 10);
	}
	else
		ft_putchar(i + 48);
}

int				ft_putnbr_endl(int n)
{
	ft_outnbr_endl(n);
	ft_putchar('\n');
	return (ft_numlen(n) + 1);
}
