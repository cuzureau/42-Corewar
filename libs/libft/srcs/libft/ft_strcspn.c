/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcspn.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/15 15:03:00 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:10:38 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strcspn() function spans the initial part of the null-terminated
**	string s as long as the characters from s do not occur in the
**	null-terminated string charset. In other words, it computes the string
**	array index of the first character of s witch IS ALSO IN charset, else the
**	the index of the first null-terminating character.
**
** RETURN VALUES
**	- ft_strcspn() returns the number of characters spanned.
*/

size_t			ft_strcspn(const char *s, const char *charset)
{
	size_t			ret;

	if (!s || !charset)
		return (ERROR);
	ret = 0;
	while (*s && ++ret)
		if (ft_strchr(charset, *s++))
			return (ret - 1);
	return (ret);
}
