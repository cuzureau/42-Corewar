/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 19:12:06 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:56:01 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strjoin() function allocates memory to contain both strings s1 and
**	s2, copies s1 into this fresh string and appends s2 to the end of fresh.
**	The fresh string is always null-terminated.
**
** RETURN VALUES
**	- ft_strjoin() returns a pointer to the fresh string. If an error occured,
**	a null-pointer is return instead.
*/

char			*ft_strjoin(const char *s1, const char *s2)
{
	char			*fresh;

	if (!s1 || !s2 || !(fresh = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
		return (NULL);
	ft_strcpy(fresh, s1);
	ft_strcat(fresh, s2);
	return (fresh);
}
