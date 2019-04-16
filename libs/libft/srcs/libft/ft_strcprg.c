/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcprg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:22:25 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 17:20:05 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strcprg() funtion purges the string str (n bytes long) of every
**	characters in the string charset. When a charater to purge is found, the
**	right portion of str is shifted by one character to the left. When n bytes
**	are spaned, ft_strprg() replaces the number of charaters purges by
**	null-terminated characters.
**
** RETURN VALUES
**	- ft_strcprg() returns the number of characters purged. If an error occured,
**	-1 is returned.
*/

int				ft_strcprg(char *str, const char *charset, size_t n)
{
	char			*dst;

	if (!str || !charset)
		return (ERROR);
	dst = str;
	while (n--)
	{
		*str = *dst;
		if (!ft_strchr(charset, *str))
			str++;
		dst++;
	}
	ft_bzero(str, dst - str);
	return (dst - str);
}
