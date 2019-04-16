/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_ischarset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 14:36:21 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:14:35 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_ischarset() function tests if the string str is full of
**	characters of the string charset.
**
** RETURN VALUES
**	- ft_str_ischarset() returns 1 if the test is true or 0 if the test is
**	false.
*/

int				ft_str_ischarset(char *str, char *charset)
{
	if (!str || !charset)
		return (0);
	while (*str)
		if (!ft_ischarset(*str++, charset))
			return (0);
	return (1);
}
