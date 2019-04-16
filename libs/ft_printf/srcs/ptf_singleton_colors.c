/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_singleton_colors.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 18:41:05 by lbrangie          #+#    #+#             */
/*   Updated: 2018/04/11 23:21:07 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void		ptf_init_sgl_part1(char **tab)
{
	tab[0] = "\e[31m";
	tab[1] = "\e[32m";
	tab[2] = "\e[34m";
	tab[3] = "\e[97m";
	tab[4] = "\e[36m";
	tab[5] = "\e[35m";
	tab[6] = "\e[33m";
	tab[7] = "\e[30m";
	tab[8] = "\e[94m";
	tab[9] = "\e[38;5;55m";
	tab[10] = "\e[38;5;202m";
	tab[11] = "\e[41m";
	tab[12] = "\e[42m";
	tab[13] = "\e[44m";
	tab[14] = "\e[107m";
}

static void		ptf_init_sgl_part2(char **tab)
{
	tab[15] = "\e[46m";
	tab[16] = "\e[45m";
	tab[17] = "\e[43m";
	tab[18] = "\e[40m";
	tab[19] = "\e[104m";
	tab[20] = "\e[48;5;55m";
	tab[21] = "\e[48;5;202m";
	tab[22] = "\e[1m";
	tab[23] = "\e[2m";
	tab[24] = "\e[4m";
	tab[25] = "\e[5m";
	tab[26] = "\e[8m";
	tab[27] = "\e[7m";
	tab[28] = "\e[3m";
	tab[29] = "\e[0m";
}

char			**ptf_sgl_colors(void)
{
	static char		*tab[EOC];

	if (!tab[0])
	{
		ptf_init_sgl_part1(tab);
		ptf_init_sgl_part2(tab);
	}
	return (tab);
}
