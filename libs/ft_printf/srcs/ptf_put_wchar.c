/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/10 14:26:49 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:30:52 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_put_wchar_1oct(t_flags *flags, t_buff *buff, t_conv *wc)
{
	if (flags->field)
		wc->flen = flags->field - 1;
	if (flags->p_flags & PRINTF_F_MINU)
	{
		ptf_buff_add_uchar(buff, 0 + (PRINTF_WC_MASK_0 & wc->n_tmp));
		while (wc->flen--)
			ptf_buff_add_char(buff, &wc->fill);
		return ;
	}
	while (wc->flen--)
		ptf_buff_add_char(buff, &wc->fill);
	ptf_buff_add_uchar(buff, 0 + (PRINTF_WC_MASK_0 & wc->n_tmp));
}

static void		ptf_put_wchar_2oct(t_flags *flags, t_buff *buff, t_conv *wc)
{
	if (flags->field)
		wc->flen = flags->field - 2;
	if (flags->p_flags & PRINTF_F_MINU)
	{
		ptf_buff_add_uchar(buff, 192 + ((PRINTF_WC_MASK_2 & wc->n_tmp) >> 6));
		ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wc->n_tmp));
		while (wc->flen--)
			ptf_buff_add_char(buff, &wc->fill);
		return ;
	}
	while (wc->flen--)
		ptf_buff_add_char(buff, &wc->fill);
	ptf_buff_add_uchar(buff, 192 + ((PRINTF_WC_MASK_2 & wc->n_tmp) >> 6));
	ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wc->n_tmp));
}

static void		ptf_put_wchar_3oct(t_flags *flags, t_buff *buff, t_conv *wc)
{
	if (flags->field)
		wc->flen = flags->field - 3;
	if (flags->p_flags & PRINTF_F_MINU)
	{
		ptf_buff_add_uchar(buff, 224 + ((PRINTF_WC_MASK_4 & wc->n_tmp) >> 12));
		ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_3 & wc->n_tmp) >> 6));
		ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wc->n_tmp));
		while (wc->flen--)
			ptf_buff_add_char(buff, &wc->fill);
		return ;
	}
	while (wc->flen--)
		ptf_buff_add_char(buff, &wc->fill);
	ptf_buff_add_uchar(buff, 224 + ((PRINTF_WC_MASK_4 & wc->n_tmp) >> 12));
	ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_3 & wc->n_tmp) >> 6));
	ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wc->n_tmp));
}

static void		ptf_put_wchar_4oct(t_flags *flags, t_buff *buff, t_conv *wc)
{
	if (flags->field)
		wc->flen = flags->field - 4;
	if (flags->p_flags & PRINTF_F_MINU)
	{
		ptf_buff_add_uchar(buff, 240 + ((PRINTF_WC_MASK_6 & wc->n_tmp) >> 18));
		ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_5 & wc->n_tmp) >> 12));
		ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_3 & wc->n_tmp) >> 6));
		ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wc->n_tmp));
		while (wc->flen--)
			ptf_buff_add_char(buff, &wc->fill);
		return ;
	}
	while (wc->flen--)
		ptf_buff_add_char(buff, &wc->fill);
	ptf_buff_add_uchar(buff, 240 + ((PRINTF_WC_MASK_6 & wc->n_tmp) >> 18));
	ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_5 & wc->n_tmp) >> 12));
	ptf_buff_add_uchar(buff, 128 + ((PRINTF_WC_MASK_3 & wc->n_tmp) >> 6));
	ptf_buff_add_uchar(buff, 128 + (PRINTF_WC_MASK_1 & wc->n_tmp));
}

void			ptf_put_wchar(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			wc;
	unsigned int	len;

	wc.n_tmp = va_arg(ap, wchar_t);
	len = ptf_numlen_ubase(wc.n_tmp, 2);
	wc.fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && !(flags->p_flags & PRINTF_F_MINU))
		wc.fill = '0';
	wc.flen = 0;
	if (len < 8 && __mb_cur_max >= 1)
		ptf_put_wchar_1oct(flags, buff, &wc);
	else if (len < 12 && __mb_cur_max >= 2)
		ptf_put_wchar_2oct(flags, buff, &wc);
	else if (len < 17 && __mb_cur_max >= 3)
		ptf_put_wchar_3oct(flags, buff, &wc);
	else if (__mb_cur_max == 4)
		ptf_put_wchar_4oct(flags, buff, &wc);
	else
	{
		ptf_buff_flush(buff);
		buff->ret = -1;
	}
}
