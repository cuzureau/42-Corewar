/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/18 20:42:27 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:47:15 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strnlen() function attempts to compute the length of the string s,
**	but never scans beyond maxlen bytes.
**
** RETURN VALUES
**	- ft_strlen() returns the number of charecters that precede the terminating
**	NULL character or maxlen, whichever is smaller.
*/

size_t			ft_strnlen(const char *s, size_t maxlen)
{
	size_t			len;

	len = 0;
	while (len < maxlen)
		if (!s[len++])
			return (--len);
	return (maxlen);
}
