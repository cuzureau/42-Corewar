/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 17:17:40 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:19:43 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memchr() function locates the first occurence of the character c in
**	string s.
**
** RETURN VALUES
**	- ft_memchr() returns a pointer to the byte located in s. If no such byte is
**	found, a NULL pointer is returned.
*/

void			*ft_memchr(const void *s, int c, size_t n)
{
	while (n--)
		if (*(unsigned char*)s++ == (unsigned char)c)
			return ((void *)s - 1);
	return (NULL);
}
