/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:41:09 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:55:13 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strlen() function computes the length of the string s.
**
** RETURN VALUES
**	- ft_strlen() returns the number of charecters that precede the terminating
**	NULL character.
*/

size_t			ft_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}
