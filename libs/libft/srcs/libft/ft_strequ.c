/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:49:11 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:03:48 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strequ() function lexicographically compares the null-terminated
**	strings s1 and s2.
**
** RETURN VALUES
**	- ft_strequ() returns 1 if s1 and s2 are equal. Otherwise, the ft_strequ()
**	returns 0;
*/

int				ft_strequ(const char *s1, const char *s2)
{
	if (!s1 || !s2)
		return (0);
	return (!ft_strcmp(s1, s2));
}
