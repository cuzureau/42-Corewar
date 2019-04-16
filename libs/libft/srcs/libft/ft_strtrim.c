/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 10:41:16 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:40:42 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strtrim() function copies the string s without white-spaces at the
**	start and end of this string. The character concidered as white-spaces are
**	the following:
**		  9 '\t'	 10 '\n'	 32 ' '
**
** RETURN VALUES
**	- ft_strtrim() returns a pointer to the fresh string. If an error occured,
**	a null-pointer is return instead.
*/

char			*ft_strtrim(const char *s)
{
	size_t			len;

	if (!s)
		return (NULL);
	s += ft_strspn(s, "\t\n ");
	len = ft_strlen(s) - 1;
	while (ft_strchr("\t\n ", s[len]))
		len--;
	return (ft_strndup(s, len + 1));
}
