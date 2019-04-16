/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 18:18:43 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:42:55 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strsub() function substracts a section of the null-terminated
**	string s, starting at the inex start and of length len. The function
**	allocates memory to store this section of s.
**
** RETURN VALUES
**	- ft_strsub() returns a pointer to the fresh string. If an error occured,
**	a null-pointer is return instead.
*/

char			*ft_strsub(const char *s, unsigned int start, size_t len)
{
	char			*fresh;
	char			*tmp;

	if (!s || !(fresh = ft_strnew(len)))
		return (NULL);
	tmp = fresh;
	s += start;
	while (s && len--)
		*tmp++ = *s++;
	return (fresh);
}
