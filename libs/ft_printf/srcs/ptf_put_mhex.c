/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_mhex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 13:23:48 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:27:48 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_get_mhex(t_flags *flags, t_conv *h, va_list ap)
{
	h->n_sign[0] = '\0';
	h->n_sign[1] = '\0';
	h->n_sign[2] = '\0';
	h->n_tmp = ptf_select_ucast(flags, ap);
	h->nlen = ptf_numlen_ubase(h->n_tmp, 16);
	if (flags->p_flags & PRINTF_F_HASH && h->n_tmp != 0)
	{
		h->n_sign[0] = '0';
		h->n_sign[1] = 'X';
	}
	if ((flags->pres >= 0) && (flags->pres > h->nlen))
		h->nlen = flags->pres;
	ptf_lltoa_base(flags, h, 16);
	h->fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && \
		!(flags->p_flags & PRINTF_F_MINU) && (flags->pres == -1))
		h->fill = '0';
	h->flen = 0;
	if (flags->field > h->nlen)
		h->flen = flags->field - h->nlen + (!h->n_sign[1]) - (!!h->n_sign[1]);
}

void			ptf_put_mhex(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			h;

	ptf_get_mhex(flags, &h, ap);
	if ((h.n_str[0] == '0' && !h.n_str[1]) && !(flags->pres))
	{
		h.flen++;
		while (h.flen-- && h.flen > 0)
			ptf_buff_add_char(buff, &h.fill);
	}
	else
		ptf_write_num(flags, buff, &h);
}
