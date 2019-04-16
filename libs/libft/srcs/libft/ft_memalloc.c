/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:54:32 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:19:31 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memalloc() function allocates a memory zone of size bytes and fills
**	this memory with bytes of value zero.
**
** RETURN VALUES
**	- ft_memalloc() returns a pointer to the allocated memory. If the allocation
**	fails, a NULL pointer is returned.
*/

void			*ft_memalloc(size_t size)
{
	void			*fresh;

	if (!(fresh = (void*)malloc(sizeof((*fresh)) * size)))
		return (NULL);
	ft_bzero(fresh, size);
	return (fresh);
}
