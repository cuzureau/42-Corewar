/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:51:09 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:16:53 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putnbr() function attempts to write the number n converted into
**	succecive characters on the standard output, a.k.a. stdout.
**
** RETURN VALUES
**	- ft_putnbr() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

static void		ft_outnbr(int n)
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

int				ft_putnbr(int n)
{
	ft_outnbr(n);
	return (ft_numlen(n));
}
