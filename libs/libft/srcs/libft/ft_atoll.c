/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoll.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/28 14:16:41 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/07 13:27:38 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long			ft_atoll(const char *str)
{
	long long		nbr;
	char			neg;

	nbr = 0;
	neg = FALSE;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		neg = TRUE;
	if (*str == '+' || *str == '-')
		str++;
	while (ft_isdigit(*str))
		nbr = ((nbr * 10) + (*str++ - 48));
	if (neg)
		return (-nbr);
	return (nbr);
}
