/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_put_arbs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/12 12:03:22 by lbrangie          #+#    #+#             */
/*   Updated: 2018/09/26 08:21:26 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ptf_put_arbs(t_flags *flags, t_buff *buff, va_list ap)
{
	t_conv			at;
	char			**tab;

	(void)flags;
	at.n_tmp = va_arg(ap, int);
	tab = ptf_sgl_colors();
	if (at.n_tmp >= RED && at.n_tmp <= EOC)
		ptf_buff_add_str(buff, tab[at.n_tmp], ptf_strlen(tab[at.n_tmp]));
}
