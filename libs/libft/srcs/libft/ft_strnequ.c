/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:56:32 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:48:34 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strnequ() function lexicographically compares the null-terminated
**	strings s1 and s2 but not more than n characters. Because, there is strings
**	to compare rather than binary data, characters after a '\0' are not
**	compared..
**
** RETURN VALUES
**	- ft_strnequ() returns 1 if s1 and s2 are equal. Otherwise, the ft_strnequ()
**	returns 0;
*/

int				ft_strnequ(const char *s1, const char *s2, size_t n)
{
	if (!s1 || !s2)
		return (0);
	return (!ft_strncmp(s1, s2, n));
}
