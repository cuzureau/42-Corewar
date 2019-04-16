/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_udec.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/04 15:08:43 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:30:22 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_get_udec(t_flags *flags, t_conv *u, va_list ap)
{
	u->n_sign[0] = '\0';
	u->n_sign[1] = '\0';
	u->n_sign[2] = '\0';
	u->n_tmp = ptf_select_ucast(flags, ap);
	u->nlen = ptf_numlen_ubase(u->n_tmp, 10);
	if ((flags->pres >= 0) && (flags->pres > u->nlen))
		u->nlen = flags->pres;
	ptf_lltoa_base(flags, u, 10);
	u->fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && \
		!(flags->p_flags & PRINTF_F_MINU) && (flags->pres == -1))
		u->fill = '0';
	u->flen = 0;
	if (flags->field > u->nlen)
		u->flen = flags->field - u->nlen + (!u->n_sign[0]);
}

void			ptf_put_udec(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			u;

	ptf_get_udec(flags, &u, ap);
	if ((u.n_str[0] == '0' && !u.n_str[1]) && !(flags->pres))
	{
		u.flen++;
		if (flags->p_flags & PRINTF_F_MINU)
		{
			ptf_buff_add_str(buff, u.n_sign, 3);
			while (u.flen-- && u.flen > 0)
				ptf_buff_add_char(buff, &u.fill);
		}
		else
		{
			while (u.flen-- && u.flen > 0)
				ptf_buff_add_char(buff, &u.fill);
			ptf_buff_add_str(buff, u.n_sign, 3);
		}
	}
	else
		ptf_write_num(flags, buff, &u);
}
