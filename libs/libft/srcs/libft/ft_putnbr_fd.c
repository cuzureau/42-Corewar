/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:02:26 by lbrangie          #+#    #+#             */
/*   Updated: 2019/03/09 14:30:21 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putnbr_fd() function attempts to write the number n converted into
**	succecive characters to the object referenced by the descriptor fd..
**
** RETURN VALUES
**	- ft_putnbr_fd() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

static void		ft_outnbr_fd(int n, int fd)
{
	unsigned int	i;

	if (n < 0)
		ft_putchar_fd('-', fd);
	i = ft_abs(n);
	if (i >= 10)
	{
		ft_putnbr_fd((i / 10), fd);
		ft_putnbr_fd((i % 10), fd);
	}
	else
		ft_putchar_fd((i + 48), fd);
}

int				ft_putnbr_fd(int n, int fd)
{
	ft_outnbr_fd(n, fd);
	return (ft_numlen(n) + 1);
}
