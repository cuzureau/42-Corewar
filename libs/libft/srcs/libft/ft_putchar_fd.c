/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:54:33 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:16:17 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putchar_fd() function attempts to write the character c to the
**	object referenced by the descriptor fd.
**
** RETURN VALUES
**	- ft_putchar_fd() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putchar_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}
