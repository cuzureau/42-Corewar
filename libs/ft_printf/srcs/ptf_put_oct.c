/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_oct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 10:22:29 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:28:09 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_get_oct(t_flags *flags, t_conv *o, va_list ap)
{
	o->n_sign[0] = '\0';
	o->n_sign[1] = '\0';
	o->n_sign[2] = '\0';
	o->n_tmp = ptf_select_ucast(flags, ap);
	o->nlen = ptf_numlen_ubase(o->n_tmp, 8);
	if (flags->p_flags & PRINTF_F_HASH)
		o->n_sign[0] = '0';
	if ((flags->pres >= 0) && (flags->pres > o->nlen))
		o->nlen = flags->pres;
	ptf_lltoa_base(flags, o, 8);
	o->fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && \
		!(flags->p_flags & PRINTF_F_MINU) && (flags->pres == -1))
		o->fill = '0';
	o->flen = 0;
	if (flags->field > o->nlen)
		o->flen = flags->field - o->nlen + (!o->n_sign[0]);
}

void			ptf_put_oct(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			o;

	ptf_get_oct(flags, &o, ap);
	if ((o.n_str[0] == '0' && !o.n_str[1]) && !(flags->pres))
	{
		o.flen++;
		if (flags->p_flags & PRINTF_F_MINU)
		{
			ptf_buff_add_str(buff, o.n_sign, 3);
			while (o.flen-- && o.flen > 0)
				ptf_buff_add_char(buff, &o.fill);
		}
		else
		{
			while (o.flen-- && o.flen > 0)
				ptf_buff_add_char(buff, &o.fill);
			ptf_buff_add_str(buff, o.n_sign, 3);
		}
	}
	else
		ptf_write_num(flags, buff, &o);
}
