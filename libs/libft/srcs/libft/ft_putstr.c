/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:35:42 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:17:34 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putstr() function attempts to write the string s on the
**	standard output, a.k.a. stdout.
**
** RETURN VALUES
**	- ft_putstr() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putstr(char const *s)
{
	if (!s)
		return (ERROR);
	return (write(1, s, ft_strlen(s)));
}
