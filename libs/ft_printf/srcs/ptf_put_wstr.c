/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_wstr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:03:02 by lbrangie          #+#    #+#             */
/*   Updated: 2018/04/16 13:21:41 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_put_wstr_oct(t_buff *buff, wchar_t wchar, int len)
{
	if (len == 1 && __mb_cur_max >= 1)
		ptf_buff_add_uchar(buff, 0 + (PRINTF_WC_MASK_0 & wchar));
	else if (len == 2 && __mb_cur_max >= 2)
	{
		ptf_buff_add_uchar(buff, 192 + ((PRINTF_WC_MASK_2 & wchar) >> 6));
		ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wchar));
	}
	else if (len == 3 && __mb_cur_max >= 3)
	{
		ptf_buff_add_uchar(buff, 224 + ((PRINTF_WC_MASK_4 & wchar) >> 12));
		ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_3 & wchar) >> 6));
		ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wchar));
	}
	else if (__mb_cur_max == 4)
	{
		ptf_buff_add_uchar(buff, 240 + ((PRINTF_WC_MASK_6 & wchar) >> 18));
		ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_5 & wchar) >> 12));
		ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_3 & wchar) >> 6));
		ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wchar));
	}
	else
	{
		ptf_buff_flush(buff);
		buff->ret = -1;
	}
}

static void		ptf_get_wstr(t_flags *flags, t_conv *wstr, va_list ap)
{
	int				i;
	int				len;

	wstr->w_str = va_arg(ap, wchar_t *);
	if (!wstr->w_str)
		wstr->w_str = L"(null)";
	wstr->fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && !(flags->p_flags & PRINTF_F_MINU))
		wstr->fill = '0';
	wstr->nlen = ptf_wstrlen(wstr->w_str);
	if ((flags->pres >= 0) && (flags->pres < wstr->nlen))
	{
		i = 0;
		wstr->nlen = 0;
		while (wstr->w_str[i] && \
		((wstr->nlen + (len = ptf_wcharlen(wstr->w_str[i])) <= flags->pres)))
			wstr->nlen += len;
	}
	wstr->flen = 0;
	if (flags->field > wstr->nlen)
		wstr->flen = flags->field - wstr->nlen;
}

void			ptf_put_wstr(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			ws;
	int				len;

	ptf_get_wstr(flags, &ws, ap);
	if (flags->p_flags & PRINTF_F_MINU)
	{
		while (ws.nlen && *ws.w_str)
		{
			len = ptf_wcharlen(*ws.w_str);
			ptf_put_wstr_oct(buff, *ws.w_str++, len);
			ws.nlen -= len;
		}
		while (ws.flen--)
			ptf_buff_add_char(buff, &ws.fill);
		return ;
	}
	while (ws.flen--)
		ptf_buff_add_char(buff, &ws.fill);
	while (*ws.w_str && ws.nlen)
	{
		len = ptf_wcharlen(*ws.w_str);
		ptf_put_wstr_oct(buff, *ws.w_str++, len);
		ws.nlen -= len;
	}
}
