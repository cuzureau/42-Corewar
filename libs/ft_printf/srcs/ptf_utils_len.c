/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_utils_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 08:40:56 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:40:57 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t			ptf_strlen(const char *s)
{
	size_t			len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

int				ptf_wcharlen(wchar_t wchar)
{
	unsigned int	tmp;

	tmp = ptf_numlen_ubase(wchar, 2);
	if (tmp < 8)
		return (1);
	else if (tmp < 12)
		return (2);
	else if (tmp < 17)
		return (3);
	else
		return (4);
}

int				ptf_wstrlen(wchar_t *wstr)
{
	int				len;
	unsigned int	tmp;

	len = 0;
	while (*wstr)
	{
		tmp = ptf_numlen_ubase(*wstr++, 2);
		if (tmp < 8)
			len += 1;
		else if (tmp < 12)
			len += 2;
		else if (tmp < 17)
			len += 3;
		else
			len += 4;
	}
	return (len);
}

size_t			ptf_numlen_base(intmax_t n, int base)
{
	size_t			len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}

size_t			ptf_numlen_ubase(uintmax_t n, int base)
{
	size_t			len;

	len = 1;
	while (n /= base)
		len++;
	return (len);
}
