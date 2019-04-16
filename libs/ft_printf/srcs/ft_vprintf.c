/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vprintf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 11:41:20 by lbrangie          #+#    #+#             */
/*   Updated: 2018/06/20 13:48:22 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_vprintf(const char *format, va_list ap)
{
	return (ft_vfprintf(stdout, format, ap));
}

int				ft_vfprintf(FILE *stream, const char *format, va_list ap)
{
	t_buff			buff;
	t_flags			flags;
	void			(**tab)(t_flags *, t_buff *, va_list);

	ptf_buff_init(&buff, stream->_file);
	tab = (g_ptf_sgl_hash)();
	while (*format)
	{
		if (*format == '%')
		{
			format = ptf_get_flags(&flags, ++format, ap);
			if (flags.type >= '@' && flags.type <= 'x')
				(*tab[flags.type - '@'])(&flags, &buff, ap);
			else if (flags.type)
				ptf_put_char(&flags, &buff, ap);
		}
		else
			ptf_buff_add_char(&buff, format++);
	}
	return (buff.ret += write(buff.fd, buff.str, buff.index));
}

int				ft_vdprintf(int fd, const char *format, va_list ap)
{
	t_buff			buff;
	t_flags			flags;
	void			(**tab)(t_flags *, t_buff *, va_list);

	ptf_buff_init(&buff, fd);
	tab = (g_ptf_sgl_hash)();
	while (*format)
	{
		if (*format == '%')
		{
			format = ptf_get_flags(&flags, ++format, ap);
			if (flags.type >= '@' && flags.type <= 'x')
				(*tab[flags.type - '@'])(&flags, &buff, ap);
			else if (flags.type)
				ptf_put_char(&flags, &buff, ap);
		}
		else
			ptf_buff_add_char(&buff, format++);
	}
	return (buff.ret += write(buff.fd, buff.str, buff.index));
}
