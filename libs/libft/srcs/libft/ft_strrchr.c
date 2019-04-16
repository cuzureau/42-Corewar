/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:43:45 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:44:30 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strrchr() function locates the last occurence of c (converted to a
**	char) in the string s. The null-terminateing character si concidered to be
**	part of s. This means if c is '\0', the function will locate the terminating
**	'\0'.
**
** RETURN VALUES
**	- ft_strrchr() returns a pointer to the located character, or NULL if c does
**	not appear in s.
*/

char			*ft_strrchr(const char *s, int c)
{
	char			*save;

	save = NULL;
	while (*s)
	{
		if (*s == c)
			save = (char *)s;
		s++;
	}
	if (*s == c)
		save = (char *)s;
	return (save);
}
