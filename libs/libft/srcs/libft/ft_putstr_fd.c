/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:57:24 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:17:56 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putstr_fd() function attempts to write the string s to the object
**	referenced by the descriptor fd.
**
** RETURN VALUES
**	- ft_putstr_fd() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putstr_fd(char const *s, int fd)
{
	if (!s)
		return (ERROR);
	return (write(fd, s, ft_strlen(s)));
}
