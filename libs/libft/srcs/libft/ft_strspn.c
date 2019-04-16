/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strspn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:21:00 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:43:58 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strspn() function spans the initial part of the null-terminated
**	string s as long as the characters from s occur in the null-terminated
**	string charset. In other words, it computes the string array index of the
**	first character of s witch IS NOT IN charset, else the the index of the
**	first null-terminating character.
**
** RETURN VALUES
**	- ft_strspn() returns the number of characters spanned.
*/

size_t			ft_strspn(const char *s, const char *charset)
{
	size_t			ret;

	if (!s || !charset)
		return (ERROR);
	ret = 0;
	while (*s && ft_strchr(charset, *s++))
		ret++;
	return (ret);
}
