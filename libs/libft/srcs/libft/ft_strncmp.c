/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:29:16 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:50:03 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strncmp() function lexicographically compares the null-terminated
**	strings s1 and s2 but not more than n characters. Because, there is strings
**	to compare rather than binary data, characters after a '\0' are not
**	compared.
**
** RETURN VALUES
**	- ft_strncmp() returns an integer greater than 0 if s1 is greater than s2,
**	less than 0 if s1 is less than s2 or equal to 0 if s1 is equal to s2.
*/

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	while (n-- && (*(unsigned char*)s1 || *(unsigned char*)s2))
		if (*(unsigned char*)s1++ != *(unsigned char*)s2++)
			return (*(unsigned char*)--s1 - *(unsigned char*)--s2);
	return (0);
}
