/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_bin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 14:01:11 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:24:20 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_get_bin(t_flags *flags, t_conv *b, va_list ap)
{
	b->n_sign[0] = '\0';
	b->n_sign[1] = '\0';
	b->n_sign[2] = '\0';
	b->n_tmp = ptf_select_ucast(flags, ap);
	b->nlen = ptf_numlen_ubase(b->n_tmp, 2);
	if (flags->p_flags & PRINTF_F_HASH && b->n_tmp != 0)
	{
		b->n_sign[0] = '0';
		b->n_sign[1] = 'b';
	}
	if ((flags->pres >= 0) && (flags->pres > b->nlen))
		b->nlen = flags->pres;
	ptf_lltoa_base(flags, b, 2);
	b->fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && \
		!(flags->p_flags & PRINTF_F_MINU) && (flags->pres == -1))
		b->fill = '0';
	b->flen = 0;
	if (flags->field > b->nlen)
		b->flen = flags->field - b->nlen + (!b->n_sign[1]) - (!!b->n_sign[1]);
}

void			ptf_put_bin(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			b;

	ptf_get_bin(flags, &b, ap);
	if ((b.n_str[0] == '0' && !b.n_str[1]) && !(flags->pres))
	{
		b.flen++;
		while (b.flen-- && b.flen > 0)
			ptf_buff_add_char(buff, &b.fill);
	}
	else
		ptf_write_num(flags, buff, &b);
}
