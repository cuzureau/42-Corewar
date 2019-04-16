/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_endl_fd.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:41:26 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:15:48 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putchar_endl_fd() function attempts to write the character c
**	followed by a '\n' character to the object referenced by the descriptor fd.
**
** RETURN VALUES
**	- ft_putchar_endl_fd() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putchar_endl_fd(char c, int fd)
{
	if ((write(fd, &c, 1) == -1) || (write(fd, "\n", 1) == -1))
		return (ERROR);
	return (2);
}
