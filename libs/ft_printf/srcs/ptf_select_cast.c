/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_select_cast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 20:06:28 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:32:03 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

uintmax_t		ptf_select_cast(t_flags *flags, va_list ap)
{
	uintmax_t		d;

	if (ptf_strlen(flags->len) == 3)
		d = va_arg(ap, uintmax_t);
	else if ((flags->len[0] == 'l') && (flags->len[1] == 'l'))
		d = va_arg(ap, long long);
	else if ((flags->len[0] == 'l') && (!flags->len[1]))
		d = va_arg(ap, long);
	else if ((flags->len[0] == 'h') && (flags->len[1] == 'h'))
		d = (signed char)va_arg(ap, int);
	else if ((flags->len[0] == 'h') && (!flags->len[1]))
		d = (short)va_arg(ap, int);
	else if ((flags->len[0] == 'z') && (!flags->len[1]))
		d = va_arg(ap, ssize_t);
	else if ((flags->len[0] == 'z') && (flags->len[1]))
		d = va_arg(ap, uintmax_t);
	else if ((flags->len[0] == 'j') && (!flags->len[1]))
		d = va_arg(ap, intmax_t);
	else if ((flags->len[0] == 'j') && (flags->len[1]))
		d = va_arg(ap, uintmax_t);
	else
		d = va_arg(ap, int);
	return (d);
}

uintmax_t		ptf_select_ucast(t_flags *flags, va_list ap)
{
	uintmax_t		d;

	if (ptf_strlen(flags->len) == 3)
		d = va_arg(ap, uintmax_t);
	else if ((flags->len[0] == 'l') && (flags->len[1] == 'l'))
		d = va_arg(ap, unsigned long long);
	else if ((flags->len[0] == 'l') && (!flags->len[1]))
		d = va_arg(ap, unsigned long);
	else if ((flags->len[0] == 'h') && (flags->len[1] == 'h'))
		d = (unsigned char)va_arg(ap, unsigned int);
	else if ((flags->len[0] == 'h') && (!flags->len[1]))
		d = (unsigned short)va_arg(ap, unsigned int);
	else if ((flags->len[0] == 'z') && (!flags->len[1]))
		d = va_arg(ap, size_t);
	else if ((flags->len[0] == 'z') && (flags->len[1]))
		d = va_arg(ap, uintmax_t);
	else if ((flags->len[0] == 'j') && (!flags->len[1]))
		d = va_arg(ap, uintmax_t);
	else if ((flags->len[0] == 'j') && (flags->len[1]))
		d = va_arg(ap, uintmax_t);
	else
		d = va_arg(ap, unsigned int);
	return (d);
}
