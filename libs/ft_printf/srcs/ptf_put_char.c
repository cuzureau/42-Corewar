/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/14 16:52:49 by lbrangie          #+#    #+#             */
/*   Updated: 2018/04/16 14:22:40 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ptf_put_char(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			c;

	if (flags->len[0] == 'l' && !flags->len[1] && flags->type == 'c')
		return (ptf_put_wchar(flags, buff, ap));
	if (flags->type != 'c')
		c.c_char = flags->type;
	else
		c.c_char = va_arg(ap, unsigned int);
	c.fill = ' ';
	if ((flags->p_flags & PRINTF_F_ZERO) && !(flags->p_flags & PRINTF_F_MINU))
		c.fill = '0';
	c.flen = 0;
	if (flags->field)
		c.flen = flags->field - 1;
	if (flags->p_flags & PRINTF_F_MINU)
	{
		ptf_buff_add_char(buff, &c.c_char);
		while (c.flen--)
			ptf_buff_add_char(buff, &c.fill);
		return ;
	}
	while (c.flen--)
		ptf_buff_add_char(buff, &c.fill);
	ptf_buff_add_char(buff, &c.c_char);
}
