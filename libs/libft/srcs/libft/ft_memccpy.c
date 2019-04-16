/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:18:08 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:19:36 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memccpy() function copies n bytes from string src to string dst,
**	until a occurence of the character c is found.
**
** RETURN VALUES
**	- If the character c occurs in the string str, ft_memccpy() returns a
**	pointer to the byte after c in dst. Otherwise, a NULL pointer is returned.
*/

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	while (n--)
		if ((*(unsigned char*)dst++ = *(unsigned char*)src++) == \
			(unsigned char)c)
			return (dst);
	return (NULL);
}
