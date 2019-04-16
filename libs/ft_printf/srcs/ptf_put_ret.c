/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_ret.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/16 16:43:26 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:29:26 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ptf_put_ret(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			ret;

	ret.ptr = va_arg(ap, void *);
	if (ptf_strlen(flags->len) == 3)
		*(uintmax_t *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'l') && (flags->len[1] == 'l'))
		*(long long *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'l') && (!flags->len[1]))
		*(long *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'h') && (flags->len[1] == 'h'))
		*(signed char *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'h') && (!flags->len[1]))
		*(short *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'z') && (!flags->len[1]))
		*(ssize_t *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'z') && (flags->len[1]))
		*(uintmax_t *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'j') && (!flags->len[1]))
		*(intmax_t *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else if ((flags->len[0] == 'j') && (flags->len[1]))
		*(uintmax_t *)ret.ptr = buff->ret + ptf_strlen(buff->str);
	else
		*(int *)ret.ptr = buff->ret + ptf_strlen(buff->str);
}
