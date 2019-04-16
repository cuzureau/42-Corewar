/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_lltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/26 07:58:48 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:17:35 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ptf_lltoa_base(t_flags *flags, t_conv *d, int base)
{
	char			*str_base;
	int				i;

	str_base = STR_BASE_LO;
	if (flags->type == 'X')
		str_base = STR_BASE_UP;
	i = 0;
	if ((flags->type == 'd' || flags->type == 'i' || flags->type == 'D') && \
		((intmax_t)d->n_tmp < 0))
	{
		d->n_sign[0] = '-';
		d->n_tmp = -d->n_tmp;
	}
	while (i < d->nlen)
	{
		d->n_str[d->nlen - i++ - 1] = str_base[ptf_abs(d->n_tmp % base)];
		d->n_tmp /= base;
	}
	d->n_str[i] = '\0';
}
