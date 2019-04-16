/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:33:01 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/21 14:39:59 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_get_opts(char **av, t_file_h *file_h)
{
	int				i;
	int				j;

	i = -1;
	while (av[++i] && av[i][0] == '-' && ft_str_isalpha(av[i] + 1))
	{
		j = 0;
		while (av[i][++j])
			if (av[i][j] == 'b')
				file_h->opts |= (1 << ASM_OPTS_B);
			else if (av[i][j] == 'p')
				file_h->opts |= (1 << ASM_OPTS_P);
			else
				asm_error(ASM_ERROR_USAGE, NULL, NULL, NULL);
		file_h->nb_opts++;
	}
}

int				main(int ac, char **av)
{
	t_file_h		file_h;
	t_prog			prog;
	t_file			*tmp;

	ft_bzero(&file_h, sizeof(t_file_h));
	asm_get_opts(av + 1, &file_h);
	asm_error(!(ac - 1 - file_h.nb_opts), NULL, NULL, NULL);
	asm_get_file(&file_h, av[1 + file_h.nb_opts]);
	if (!file_h.head)
		asm_error(ASM_ERROR_EMPTY, &file_h, NULL, NULL);
	tmp = asm_get_header(&file_h, &prog);
	asm_get_prog(&file_h, &prog, tmp);
	asm_check_label(&file_h, &prog);
	asm_write_output(&file_h, &prog);
	ft_printf("Writing output program to %s\n", file_h.dst_name);
	asm_del_file(&file_h);
	asm_del_prog(&prog);
	return (0);
}
