/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 10:39:21 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:04:39 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_itoa() function converts the n integer in a null-terminated string
**	that has been allocated. Negative numbers are handled.
**
** RETURN VALUES
**	- ft_itoa() returns the string that has been allocated. If an error
**	happened, a NULL pointer is returned.
*/

char			*ft_itoa(int n)
{
	return (ft_itoa_base(n, 10));
}
