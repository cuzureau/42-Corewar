/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:25:47 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:11:51 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strcmp() function lexicographically compares the null-terminated
**	strings s1 and s2.
**
** RETURN VALUES
**	- ft_strcmp() returns an integer greater than 0 if s1 is greater than s2,
**	less than 0 if s1 is less than s2 or equal to 0 if s1 is equal to s2.
*/

int				ft_strcmp(const char *s1, const char *s2)
{
	while (*(unsigned char*)s1 || *(unsigned char*)s2)
		if (*(unsigned char*)s1++ != *(unsigned char*)s2++)
			return (*(unsigned char*)--s1 - *(unsigned char*)--s2);
	return (0);
}
