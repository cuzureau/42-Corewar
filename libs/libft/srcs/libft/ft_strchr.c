/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:40:37 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:11:22 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strchr() function locates the first occurence of c (converted to a
**	char) in the string s. The null-terminateing character si concidered to be
**	part of s. This means if c is '\0', the function will locate the terminating
**	'\0'.
**
** RETURN VALUES
**	- ft_strchr() returns a pointer to the located character, or NULL if c does
**	not appear in s.
*/

char			*ft_strchr(const char *s, int c)
{
	while (*s != c)
		if (!*s++)
			return (NULL);
	return ((char*)s);
}
