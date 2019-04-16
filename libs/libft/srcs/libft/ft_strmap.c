/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:20:24 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:52:01 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strmap() function applies the f function on every characters of the
**	string s and creates a new string fresh that is the result of those
**	applications.
**
** RETURN VALUES
**	- ft_strmap() returns a pointer to the fresh string, or NULL if an error
**	occured.
*/

char			*ft_strmap(const char *s, char (*f)(char))
{
	char			*fresh;
	char			*tmp;

	if (!s || !f || !(fresh = ft_strnew(ft_strlen(s))))
		return (NULL);
	tmp = fresh;
	while (*s)
		*tmp++ = f(*s++);
	return (fresh);
}
