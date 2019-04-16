/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:26:11 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:54:42 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strmapi() function applies the f function on every characters of
**	the string s, by giving to f the address of the character and the index of
**	this character, and creates a new string fresh that is the result of those
**	applications.
**
** RETURN VALUES
**	- ft_strmapi() returns a pointer to the fresh string, or NULL if an error
**	occured.
*/

char			*ft_strmapi(const char *s, char (*f)(unsigned int, char))
{
	int				i;
	char			*fresh;

	if (!s || !f || !(fresh = ft_strnew(ft_strlen(s))))
		return (NULL);
	i = -1;
	while (s[++i])
		fresh[i] = f(i, s[i]);
	return (fresh);
}
