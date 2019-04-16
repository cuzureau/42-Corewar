/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_endl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/16 15:54:47 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:17:39 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putstr_endl() function attempts to write the string s followed by a
**	'\n' character on the standard output, a.k.a. stdout.
**
** RETURN VALUES
**	- ft_putstr_endl() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putstr_endl(const char *s)
{
	size_t			len;

	if (!s)
		return (ERROR);
	if ((write(1, s, len = ft_strlen(s)) == -1) || (write(1, "\n", 1) == -1))
		return (ERROR);
	return (len + 1);
}
