/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:14:27 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 15:41:08 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memset() function writes len bytes of value c to the string b.
**
** RETURN VALUES
**	- ft_memset() returns a pointer to the begening of the string b.
*/

void			*ft_memset(void *b, int c, size_t len)
{
	size_t			i;

	i = 0;
	while (i < len)
		((unsigned char*)b)[i++] = (unsigned char)c;
	return (b);
}
