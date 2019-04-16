/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ischarset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:22:54 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:00:59 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_ischarset() function test if the char c is a character of the
**	string charset.
**
** RETURN VALUES
**	- ft_ischarset() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_ischarset(char c, char *charset)
{
	while (*charset)
		if (*charset++ == c)
			return (TRUE);
	return (FALSE);
}
