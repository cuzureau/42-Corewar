/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 16:40:07 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:21:50 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memmove() function copies len bytes from string src to string dst.
**	If the two strings overlap, the copy is done in a non-destructive way.
**
** RETURN VALUES
**	- ft_memmove() returns a pointer to the original value of dst.
*/

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	if (src < dst)
		while (len--)
			((unsigned char*)dst)[len] = ((unsigned char*)src)[len];
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
