/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_ptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/09 11:45:58 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:28:25 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ptf_put_ptr(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			p;

	p.n_sign[0] = '0';
	p.n_sign[1] = 'x';
	p.n_sign[2] = '\0';
	p.n_tmp = va_arg(ap, unsigned long);
	p.nlen = ptf_numlen_ubase(p.n_tmp, 16);
	if ((flags->pres >= 0) && (flags->pres > p.nlen))
		p.nlen = flags->pres;
	ptf_lltoa_base(flags, &p, 16);
	p.fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && \
		!(flags->p_flags & PRINTF_F_MINU) && (flags->pres == -1))
		p.fill = '0';
	p.flen = 0;
	if (flags->field > p.nlen)
		p.flen = flags->field - p.nlen + (!p.n_sign[1]) - (!!p.n_sign[1]);
	if ((p.n_str[0] == '0' && !p.n_str[1]) && !(flags->pres))
	{
		p.flen++;
		p.n_str[0] = '\0';
	}
	ptf_write_num(flags, buff, &p);
}
