/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_endl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:35:37 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:15:18 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putchar_endl() function attempts to write the character c followed
**	by a '\n' character on the standard output, a.k.a. stdout.
**
** RETURN VALUES
**	- ft_putchar_endl() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putchar_endl(char c)
{
	if ((write(1, &c, 1) == -1) || (write(1, "\n", 1) == -1))
		return (ERROR);
	return (2);
}
