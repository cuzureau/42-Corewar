/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:07:59 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:49:27 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strncpy() function copies at most len characters from src into dst.
**	If src is less than len characters long, the remainder of dst is filled with
**	'\0' characters. Otherwise, dst is not terminated.
**
** RETURN VALUES
**	- ft_strncpy() returns dst.
*/

char			*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t			n;

	n = ft_strnlen(src, len);
	if (n != len)
		ft_memset(dst + n, '\0', len - n);
	return ((char *)ft_memcpy(dst, src, n));
}
