/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_str.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:16:18 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:29:52 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_get_str(t_flags *flags, t_conv *str, va_list ap)
{
	str->s_str = va_arg(ap, char *);
	if (!str->s_str)
		str->s_str = "(null)";
	str->fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && !(flags->p_flags & PRINTF_F_MINU))
		str->fill = '0';
	str->nlen = ptf_strlen(str->s_str);
	if ((flags->pres >= 0) && (flags->pres < str->nlen))
		str->nlen = flags->pres;
	str->flen = 0;
	if (flags->field > str->nlen)
		str->flen = flags->field - str->nlen;
}

void			ptf_put_str(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			str;

	if (flags->len[0] == 'l' && !flags->len[1])
		return (ptf_put_wstr(flags, buff, ap));
	ptf_get_str(flags, &str, ap);
	if (flags->p_flags & PRINTF_F_MINU)
	{
		ptf_buff_add_str(buff, str.s_str++, str.nlen);
		while (str.flen--)
			ptf_buff_add_char(buff, &str.fill);
		return ;
	}
	while (str.flen--)
		ptf_buff_add_char(buff, &str.fill);
	ptf_buff_add_str(buff, str.s_str++, str.nlen);
}
