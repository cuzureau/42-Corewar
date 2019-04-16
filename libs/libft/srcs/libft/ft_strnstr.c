/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 16:53:46 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:46:13 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strnstr() function locates the first occurence of the
**	null-terminated string needle in the null-terminated string haystack, where
**	not more than n characters are searched. Character that appears after a '\0'
**	are not searched.
**
** RETURN VALUES
**	- ft_strnstr() returns haystack if needle is an empty string, NULL if needle
**	occurs nowhere in haystack, otherwise, a pointer to the first character of
**	the first occurence of needle.
*/

char			*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t			size;
	const char		*save;

	if (!*needle)
		return ((char*)haystack);
	size = ft_strlen(needle);
	save = haystack;
	haystack += n;
	while ((save = ft_strchr(save, *needle)) && ((save + size) <= haystack))
		if (!ft_strncmp(save++, needle, size))
			return ((char*)--save);
	return (NULL);
}
