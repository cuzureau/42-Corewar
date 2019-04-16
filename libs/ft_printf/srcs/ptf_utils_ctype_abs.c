/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_utils_ctype_abs.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 08:40:44 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:40:50 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long		ptf_abs(long long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int				ptf_isalpha(int c)
{
	return ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'));
}

int				ptf_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int				ptf_isflag(char c)
{
	return (c == '#' || c == '-' || c == '+' || c == ' ' || c == 'h' || \
			c == 'l' || c == 'j' || c == 'z' || c == '.' || c == '*' || \
			c == '\'' || ptf_isdigit(c));
}
