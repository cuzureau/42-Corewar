/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strpbrk.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 14:19:07 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:45:24 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strpbrk() function locates in the null-terminated string s the
**	first occurence of any character in the string charset.
**
** RETURN VALUES
**	- ft_strpbrk() returns a pointer to the character located. If no characters
**	from charset occur anywhere in s, the function returns NULL.
*/

char			*ft_strpbrk(const char *s, const char *charset)
{
	if (!s || !charset)
		return (NULL);
	while (*s)
		if (ft_strchr(charset, *s++))
			return ((char *)--s);
	return (NULL);
}
