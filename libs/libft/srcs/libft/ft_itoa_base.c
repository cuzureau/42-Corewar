/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 11:28:00 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:05:14 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_itoa_base() function converts the value integer with a base of
**	digits in a null-terminated string that has been allocated.
**	For exemple:
**		42 in base 10 is "42"
**		42 in base 16 is "2A"
**		42 in base  2 is "101010"
**
** RETURN VALUES
**	- ft_itoa_base() returns the string that has been allocated. If an error
**	happened, a NULL pointer is returned.
*/

char			*ft_itoa_base(int value, int base)
{
	char			*str_base;
	char			*fresh;
	unsigned int	i;
	size_t			len;

	if (!value)
		return (ft_strdup("0"));
	len = ft_numlen_base(ft_abs(value), base) + ft_isneg(value);
	if (base < 2 || base > 16 || !(fresh = ft_strnew(len)))
		return (NULL);
	i = 0;
	str_base = STR_BASE_UP;
	if (value < 0 && base == 10)
		fresh[0] = '-';
	while (value)
	{
		fresh[len - i++ - 1] = str_base[ft_abs(value % base)];
		value /= base;
	}
	return (fresh);
}
