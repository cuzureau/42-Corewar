/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/01 10:54:51 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:49:05 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strndup() function allocates sufficient memory for a copy of a
**	maximum of n bytes of the string s and does the copy.
**
** RETURN VALUES
**	- ft_strndup() returns a pointer to the memory allocates. If an error
**	occures a NULL pointer is returned.
*/

char			*ft_strndup(const char *s, size_t n)
{
	unsigned int	len;
	char			*fresh;

	len = ft_strnlen(s, n);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	return ((char *)ft_memcpy(fresh, s, len));
}
