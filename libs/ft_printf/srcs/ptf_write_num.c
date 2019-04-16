/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_write_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/06 17:07:13 by lbrangie          #+#    #+#             */
/*   Updated: 2018/04/09 13:27:47 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_write_num_left(t_flags *flags, t_buff *buff, t_conv *num)
{
	if (!((flags->type == 'o' || flags->type == 'O') && \
		(num->n_str[0] == '0')))
		ptf_buff_add_str(buff, num->n_sign, 3);
	ptf_buff_add_str(buff, num->n_str, num->nlen);
	while (num->flen-- && num->flen > 0)
		ptf_buff_add_char(buff, &num->fill);
}

static void		ptf_write_num_zero(t_flags *flags, t_buff *buff, t_conv *num)
{
	if (!((flags->type == 'o' || flags->type == 'O') && \
		(num->n_str[0] == '0')))
		ptf_buff_add_str(buff, num->n_sign, 3);
	while (num->flen-- && num->flen > 0)
		ptf_buff_add_char(buff, &num->fill);
	ptf_buff_add_str(buff, num->n_str, num->nlen);
}

static void		ptf_write_num_default(t_flags *flags, t_buff *buff, t_conv *num)
{
	while (num->flen-- && num->flen > 0)
		ptf_buff_add_char(buff, &num->fill);
	if (!((flags->type == 'o' || flags->type == 'O') && \
		(num->n_str[0] == '0')))
		ptf_buff_add_str(buff, num->n_sign, 3);
	ptf_buff_add_str(buff, num->n_str, num->nlen);
}

void			ptf_write_num(t_flags *flags, t_buff *buff, t_conv *num)
{
	if ((flags->type == 'o' || flags->type == 'O') && \
		(num->n_str[0] == '0' && !num->n_str[1]) && \
		flags->p_flags & PRINTF_F_HASH)
	{
		num->n_str[0] = '\0';
		num->flen++;
	}
	if (flags->p_flags & PRINTF_F_MINU)
		ptf_write_num_left(flags, buff, num);
	else if (flags->pres == -1 && flags->p_flags & PRINTF_F_ZERO)
		ptf_write_num_zero(flags, buff, num);
	else
		ptf_write_num_default(flags, buff, num);
}
