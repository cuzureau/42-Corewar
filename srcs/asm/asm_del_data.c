/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_del_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 04:51:39 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/16 05:45:52 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_del_file(t_file_h *file_h)
{
	t_file			*tmp;

	ft_strdel(&file_h->file_name);
	ft_strdel(&file_h->dst_name);
	while (file_h->head)
	{
		tmp = file_h->head;
		file_h->head = file_h->head->next;
		ft_strdel(&tmp->line);
		free(tmp);
	}
}

static void		asm_del_arg(t_arg *arg)
{
	t_arg			*tmp;

	while (arg)
	{
		tmp = arg;
		arg = arg->next;
		ft_strdel(&tmp->str);
		free(tmp);
	}
}

static void		asm_del_inst(t_inst_h inst_h)
{
	t_inst			*tmp;

	while (inst_h.head)
	{
		tmp = inst_h.head;
		inst_h.head = inst_h.head->next;
		ft_tabdel((void **)tmp->tab_args);
		asm_del_arg(tmp->arg);
		free(tmp);
	}
}

static void		asm_del_label(t_label *label)
{
	t_label			*tmp;

	while (label)
	{
		tmp = label;
		label = label->next;
		ft_strdel(&tmp->name);
		free(tmp);
	}
}

void			asm_del_prog(t_prog *prog)
{
	asm_del_inst(prog->inst_h);
	asm_del_label(prog->label);
}
