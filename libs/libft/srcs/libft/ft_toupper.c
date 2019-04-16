/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:24:39 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 10:48:16 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_toupper() function convert a lower-case letter to the corresponding
**	upper-case letter.
**
** RETURN VALUES
**	- ft_toupper() returns the upper-case letter if the argument is a lower-case
**	letter. If the argument isn't a lower-case letter, it is returned unchanged.
*/

int				ft_toupper(int c)
{
	if (ft_islower(c))
		return (c - 32);
	return (c);
}
