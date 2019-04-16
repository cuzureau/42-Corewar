/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strprg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 14:19:43 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 17:16:26 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strprg() funtion purges the string str (n bytes long) of every c
**	characters. When a charater to purge is found, the right portion of str is
**	shifted by one character to the left. When n bytes are spaned, ft_strprg()
**	replaces the number of charaters purges by null-terminated characters.
**
** RETURN VALUES
**	- ft_strprg() returns the number of characters purged. If an error occured,
**	-1 is returned.
*/

int				ft_strprg(char *str, char c, size_t n)
{
	char			*dst;

	if (!str)
		return (ERROR);
	dst = str;
	while (n--)
	{
		*str = *dst;
		if (*str != c)
			str++;
		dst++;
	}
	ft_bzero(str, dst - str);
	return (dst - str);
}
