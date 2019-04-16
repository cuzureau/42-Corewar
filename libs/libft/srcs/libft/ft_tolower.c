/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 13:27:15 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 10:47:45 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_tolower() function convert an upper-case letter to the
**	corresponding lower-case letter.
**
** RETURN VALUES
**	- ft_tolower() returns the lower-case letter if the argument is an
**	upper-case letter. If the argument isn't an upper-case letter, it is
**	returned unchanged.
*/

int				ft_tolower(int c)
{
	if (ft_isupper(c))
		return (c + 32);
	return (c);
}
