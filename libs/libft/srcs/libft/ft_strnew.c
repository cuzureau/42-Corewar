/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:02:57 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:48:04 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strnew() function allocates size char into a string. The allocated
**	memory is filled with char of value zero.
**
** RETURN VALUES
**	- ft_strnew() returns a pointer to the allocated string.
*/

char			*ft_strnew(size_t size)
{
	char			*fresh;

	if (!(fresh = (char*)malloc(sizeof(*fresh) * (++size))))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
