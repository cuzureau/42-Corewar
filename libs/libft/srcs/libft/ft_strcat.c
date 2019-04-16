/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/16 18:38:55 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:13:46 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strcat() function appends a copy of the null-terminated string src
**	to the end of the null-terminated string dst, then adds a terminating '\0'
**	character.
**
** RETURN VALUES
**	- ft_strcat() returns the pointer dst.
*/

char			*ft_strcat(char *dst, const char *src)
{
	ft_strcpy(dst + ft_strlen(dst), src);
	return (dst);
}
