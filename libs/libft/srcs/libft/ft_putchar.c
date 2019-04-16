/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:33:42 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:14:53 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putchar() function attempts to write the character c on the
**	standard output, a.k.a. stdout.
**
** RETURN VALUES
**	- ft_putchar() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putchar(char c)
{
	return (write(1, &c, 1));
}
