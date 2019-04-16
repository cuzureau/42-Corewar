/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_hash.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/28 12:55:26 by lbrangie          #+#    #+#             */
/*   Updated: 2018/06/20 13:48:11 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_init_sgl_part3(void (**tab)(t_flags *, t_buff *, va_list))
{
	tab[40] = ptf_put_char;
	tab[41] = ptf_put_dec;
	tab[42] = ptf_put_char;
	tab[43] = ptf_put_char;
	tab[44] = ptf_put_char;
	tab[45] = ptf_put_char;
	tab[46] = ptf_put_ret;
	tab[47] = ptf_put_oct;
	tab[48] = ptf_put_ptr;
	tab[49] = ptf_put_char;
	tab[50] = ptf_put_char;
	tab[51] = ptf_put_str;
	tab[52] = ptf_put_char;
	tab[53] = ptf_put_udec;
	tab[54] = ptf_put_char;
	tab[55] = ptf_put_char;
	tab[56] = ptf_put_hex;
}

static void		ptf_init_sgl_part2(void (**tab)(t_flags *, t_buff *, va_list))
{
	tab[20] = ptf_put_char;
	tab[21] = ptf_put_ludec;
	tab[22] = ptf_put_char;
	tab[23] = ptf_put_char;
	tab[24] = ptf_put_mhex;
	tab[25] = ptf_put_char;
	tab[26] = ptf_put_char;
	tab[27] = ptf_put_char;
	tab[28] = ptf_put_char;
	tab[29] = ptf_put_char;
	tab[30] = ptf_put_char;
	tab[31] = ptf_put_char;
	tab[32] = ptf_put_char;
	tab[33] = ptf_put_char;
	tab[34] = ptf_put_bin;
	tab[35] = ptf_put_char;
	tab[36] = ptf_put_dec;
	tab[37] = ptf_put_char;
	tab[38] = ptf_put_char;
	tab[39] = ptf_put_char;
}

static void		ptf_init_sgl_part1(void (**tab)(t_flags *, t_buff *, va_list))
{
	tab[0] = ptf_put_arbs;
	tab[1] = ptf_put_char;
	tab[2] = ptf_put_char;
	tab[3] = ptf_put_wchar;
	tab[4] = ptf_put_ldec;
	tab[5] = ptf_put_char;
	tab[6] = ptf_put_char;
	tab[7] = ptf_put_char;
	tab[8] = ptf_put_char;
	tab[9] = ptf_put_char;
	tab[10] = ptf_put_char;
	tab[11] = ptf_put_char;
	tab[12] = ptf_put_char;
	tab[13] = ptf_put_char;
	tab[14] = ptf_put_char;
	tab[15] = ptf_put_loct;
	tab[16] = ptf_put_char;
	tab[17] = ptf_put_char;
	tab[18] = ptf_put_char;
	tab[19] = ptf_put_wstr;
}

void			(**g_ptf_sgl_hash(void))(t_flags *, t_buff *, va_list)
{
	static void		(*tab[57])(t_flags*, t_buff*, va_list);

	if (!tab[0])
	{
		ptf_init_sgl_part1(tab);
		ptf_init_sgl_part2(tab);
		ptf_init_sgl_part3(tab);
	}
	return (tab);
}
