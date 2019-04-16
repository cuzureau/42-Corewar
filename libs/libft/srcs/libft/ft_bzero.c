/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 15:27:25 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:59:30 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_bzero() write n '\0' bytes at the s address.
*/

void			ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}
