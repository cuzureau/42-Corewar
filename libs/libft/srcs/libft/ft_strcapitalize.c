/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 12:05:56 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 17:43:10 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strcapitalize() function converts capitalize very words of the
**	null-terminated string str. A word is a string of alphanumeric characters.
**	In other words, the first letter of each word is converted to the upper-case
**	version of the letter and the other letters are lowered.
**
** RETURN VALUES
**	- ft_strcapitalize() returns a pointer to converted string. If an error
**	occures, a NULL pointer is returned.
*/

char			*ft_strcapitalize(char *str)
{
	unsigned int	i;

	i = 0;
	if (!str)
		return (NULL);
	str = ft_str_tolower(str);
	while (str[i])
	{
		if (ft_islower(str[0]))
			str[0] -= 32;
		if (!ft_isgraph(str[i]))
			if (ft_islower(str[i + 1]) && str[i + 1])
				str[i + 1] -= 32;
		if (ft_ispunct(str[i]))
			if (ft_islower(str[i + 1]) && str[i + 1])
				str[i + 1] -= 32;
		i++;
	}
	return (str);
}
