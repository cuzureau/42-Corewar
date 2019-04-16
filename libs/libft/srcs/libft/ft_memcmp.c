/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:41:04 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:19:51 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memcmp() function compares both string s1 and s2. Both of those
**	string are assumed to be n bytes long.
**
** RETURN VALUES
**	- ft_memcp() return zero if both strings a identical. Otherwise, the
**	function returns the difference between the first two differing bytes.
*/

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	while (n--)
		if (*(unsigned char*)s1++ != *(unsigned char*)s2++)
			return (*(unsigned char*)--s1 - *(unsigned char*)--s2);
	return (0);
}
