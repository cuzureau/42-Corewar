/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/08 14:07:24 by lbrangie          #+#    #+#             */
/*   Updated: 2018/04/13 19:32:48 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	int				ret;
	va_list			ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	ret = ft_vfprintf(stdout, format, ap);
	va_end(ap);
	return (ret);
}

int				ft_fprintf(FILE *stream, const char *format, ...)
{
	int				ret;
	va_list			ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	ret = ft_vfprintf(stream, format, ap);
	va_end(ap);
	return (ret);
}

int				ft_dprintf(int fd, const char *format, ...)
{
	int				ret;
	va_list			ap;

	if (!format)
		return (-1);
	va_start(ap, format);
	ret = ft_vdprintf(fd, format, ap);
	va_end(ap);
	return (ret);
}
