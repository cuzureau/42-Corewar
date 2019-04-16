/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_endl_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 16:02:15 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:17:45 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putstr_endl_fd() function attempts to write the string s followed
**	by a '\n' character to the object referenced by the descriptor fd.
**
** RETURN VALUES
**	- ft_putstr_endl_fd() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putstr_endl_fd(const char *s, int fd)
{
	size_t			len;

	if (!s)
		return (ERROR);
	if ((write(fd, s, len = ft_strlen(s)) == -1) || (write(fd, "\n", 1) == -1))
		return (ERROR);
	return (len + 1);
}
