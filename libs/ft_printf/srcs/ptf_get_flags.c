/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_get_flags.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/18 13:37:12 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:18:53 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_init_flags(t_flags *flags, char **str_flags)
{
	flags->p_flags = 0;
	flags->len[0] = '\0';
	flags->len[1] = '\0';
	flags->len[2] = '\0';
	flags->len[3] = '\0';
	flags->type = '\0';
	flags->field = 0;
	flags->pres = -1;
	*str_flags = PRINTF_FLAGS;
}

static int		ptf_get_pres(t_flags *flags, const char *format, va_list ap)
{
	unsigned int	i;

	flags->pres = 0;
	if (*format == '*')
	{
		if ((flags->pres = va_arg(ap, int)) < 0)
			flags->pres = -1;
		return (1);
	}
	else if (ptf_isdigit(*format))
	{
		i = 0;
		while (ptf_isdigit(*format) && ++i)
			flags->pres = ((flags->pres * 10) + (*format++ - 48));
		return (i);
	}
	return (0);
}

static int		ptf_get_field(t_flags *flags, const char *format, va_list ap)
{
	int				i;

	flags->field = 0;
	if (*format == '*')
	{
		if ((flags->field = va_arg(ap, int)) < 0)
		{
			flags->p_flags |= PRINTF_F_MINU;
			flags->field = -flags->field;
		}
		return (0);
	}
	i = 0;
	while (ptf_isdigit(*format) && ++i)
		flags->field = ((flags->field * 10) + (*format++ - 48));
	return (i - 1);
}

const char		*ptf_get_flags(t_flags *flags, const char *format, va_list ap)
{
	char			*str_flags;
	int				i;
	unsigned int	j;

	ptf_init_flags(flags, &str_flags);
	j = 0;
	while (ptf_isflag(*format))
	{
		i = -1;
		while (str_flags[++i])
			if (*format == str_flags[i])
				flags->p_flags |= (1 << i);
		if (j < 3 && ptf_isalpha(*format))
			flags->len[j++] = *format;
		if ((ptf_isdigit(*format) && *format != '0') || (*format == '*'))
			format += ptf_get_field(flags, format, ap);
		if (*format && *format++ == '.')
			format += ptf_get_pres(flags, format, ap);
	}
	if (*format)
		flags->type = *format++;
	return (format);
}
