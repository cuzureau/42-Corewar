/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 14:59:23 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 17:03:46 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strrev() function reverses the string str. That means the string
**	"Hello World" will be transformed into "dlroW olleH".
**
** RETURN VALUES
**	- ft_strrev() returns a pointer to the begining of the reversed string str.
*/

char			*ft_strrev(char *str)
{
	int				i;
	int				len;
	char			tmp;

	i = 0;
	len = (ft_strlen(str) - 1);
	while (i <= (len / 2))
	{
		tmp = str[i];
		str[i] = str[len - i];
		str[len - i] = tmp;
		i++;
	}
	return (str);
}
