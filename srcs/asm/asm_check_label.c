/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_check_label.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/19 10:20:17 by cuzureau          #+#    #+#             */
/*   Updated: 2019/02/20 18:59:42 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_find_label(t_prog *prog, char *label)
{
	t_label			*tmp;

	tmp = prog->label;
	while (tmp)
	{
		if (ft_strequ((ft_strchr(label, CHAR_LABEL) + 1), tmp->name))
			return (tmp->addr);
		tmp = tmp->next;
	}
	return (-1);
}

void			asm_check_label(t_file_h *file_h, t_prog *prog)
{
	t_inst			*tmp;
	t_arg			*tmp_arg;
	int				addr;

	tmp = prog->inst_h.head;
	while (tmp)
	{
		tmp_arg = tmp->arg;
		while (tmp_arg)
		{
			if (tmp_arg->label == 1)
			{
				if ((addr = asm_find_label(prog, tmp_arg->str)) != -1)
					tmp_arg->label = addr;
				else
					asm_error(ASM_ERROR_LABEL, file_h, prog, NULL);
			}
			else
				tmp_arg->label = -1;
			tmp_arg = tmp_arg->next;
		}
		tmp = tmp->next;
	}
}
