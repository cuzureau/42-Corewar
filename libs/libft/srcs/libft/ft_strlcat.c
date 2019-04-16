/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 10:30:18 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:55:31 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strlcat() function tries to append the null-terminated string src
**	to the end of dst. It will append at most size - len-of-dst - 1 bytes,
**	null-terminating the result. This function guarantees to null-terminate the
**	result, as long as there is at least one byte free in dst. That means that
**	the null-terminating byte should be included in size.
**
** RETURN VALUES
**	- ft_strlcat() returns the total length of the string it tried to create.
**	That means the initial length of dst plus the length of dst.
**	It is important to note that if ft_strlcat() traverses size bytes in dst
**	without finding a NULL, the length of dst is concidered to be size long and
**	the destination will NOT be null-terminated.
*/

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			len;

	len = ft_strlen(dst);
	if (len >= size)
		return (ft_strlen(src) + size);
	ft_strncat(dst, src, size - len - 1);
	return (ft_strlen(src) + len);
}
