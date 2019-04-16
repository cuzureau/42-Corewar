/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 10:53:44 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:32:45 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strdup() function allocates sufficient memory for a copy of the
**	string s and does the copy.
**
** RETURN VALUES
**	- ft_strdup() returns a pointer to the memory allocates. If an error,
**	occures, a NULL pointer is returned.
*/

char			*ft_strdup(const char *s)
{
	unsigned int	len;
	char			*fresh;

	len = ft_strlen(s);
	if (!(fresh = ft_strnew(len)))
		return (NULL);
	return ((char *)ft_memcpy(fresh, s, len));
}
