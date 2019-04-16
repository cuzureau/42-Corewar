/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 15:30:02 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:20:49 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memcpy() function copies n bytes from string src to string dst.
**
** RETURN VALUES
**	- ft_memcpy() returns a pointer to the original value of dst.
*/

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	void			*d;

	d = dst;
	while (n--)
		*(unsigned char*)dst++ = *(unsigned char*)src++;
	return (d);
}
