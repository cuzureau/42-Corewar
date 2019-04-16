/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_ldec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 11:41:27 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:27:09 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_get_ldec(t_flags *flags, t_conv *d, va_list ap)
{
	d->n_sign[0] = '\0';
	d->n_sign[1] = '\0';
	d->n_sign[2] = '\0';
	d->n_tmp = va_arg(ap, long);
	d->nlen = ptf_numlen_base(d->n_tmp, 10);
	if (flags->p_flags & PRINTF_F_SPAC)
		d->n_sign[0] = ' ';
	if (flags->p_flags & PRINTF_F_PLUS)
		d->n_sign[0] = '+';
	if ((flags->pres >= 0) && (flags->pres > d->nlen))
		d->nlen = flags->pres;
	ptf_lltoa_base(flags, d, 10);
	d->fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && \
		!(flags->p_flags & PRINTF_F_MINU) && (flags->pres == -1))
		d->fill = '0';
	d->flen = 0;
	if (flags->field > d->nlen)
		d->flen = flags->field - d->nlen + (!d->n_sign[0]);
}

void			ptf_put_ldec(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			d;

	ptf_get_ldec(flags, &d, ap);
	if ((d.n_str[0] == '0' && !d.n_str[1]) && !(flags->pres))
	{
		d.flen++;
		if (flags->p_flags & PRINTF_F_MINU)
		{
			ptf_buff_add_str(buff, d.n_sign, 3);
			while (d.flen-- && d.flen > 0)
				ptf_buff_add_char(buff, &d.fill);
		}
		else
		{
			while (d.flen-- && d.flen > 0)
				ptf_buff_add_char(buff, &d.fill);
			ptf_buff_add_str(buff, d.n_sign, 3);
		}
	}
	else
		ptf_write_num(flags, buff, &d);
}
