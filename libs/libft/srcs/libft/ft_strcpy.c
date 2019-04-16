/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 18:01:21 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:13:22 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strcpy() function copies the string src to dst (including the
**	terminating '\0' character).
**
** RETURN VALUES
**	- ft_strcpy() returns dst.
*/

char			*ft_strcpy(char *dst, const char *src)
{
	return ((char *)ft_memcpy(dst, src, ft_strlen(src) + 1));
}
