/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:41:16 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:51:07 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strncat() function appends not more than len characters from src to
**	the end of the null-terminated string dst, then adds a terminating '\0'
**	character.
**
** RETURN VALUES
**	- ft_strncat() returns the pointer dst.
*/

char			*ft_strncat(char *dst, const char *src, size_t len)
{
	char			*save;
	size_t			size;

	save = dst;
	dst += ft_strlen(dst);
	size = ft_strnlen(src, len);
	dst[size] = '\0';
	ft_memcpy(dst, src, size);
	return (save);
}
