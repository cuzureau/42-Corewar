/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 17:09:00 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:57:05 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_striteri() function applies the f function on every characters of
**	the strinfg s by giving to f the address of the character and the index of
**	this character.
*/

void			ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int				i;

	if (!s || !f)
		return ;
	i = -1;
	while (s[++i])
		f(i, &s[i]);
}
