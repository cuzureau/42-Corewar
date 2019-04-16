/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 15:40:06 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:43:28 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strstr() function locates the first occurence of the
**	null-terminated string needle in the null-terminated string haystack.
**
** RETURN VALUES
**	- ft_strstr() returns haystack if needle is an empty string, NULL if needle
**	occurs nowhere in haystack, otherwise, a pointer to the first character of
**	the first occurence of needle.
*/

char			*ft_strstr(const char *haystack, const char *needle)
{
	size_t			size;

	if (!*needle)
		return ((char*)haystack);
	size = ft_strlen(needle);
	while ((haystack = ft_strchr(haystack, *needle)))
		if (!ft_strncmp(haystack++, needle, size))
			return ((char*)--haystack);
	return (NULL);
}
