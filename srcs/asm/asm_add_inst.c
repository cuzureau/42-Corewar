/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_add_inst.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:46:16 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/21 13:09:51 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_init_sgl(t_op *op_tab)
{
	op_tab[0] = (t_op){"live", 1, {T_DIR}, 1, 0, 4};
	op_tab[9] = (t_op){"ld", 2, {T_DIR | T_IND, T_REG}, 2, 1, 4};
	op_tab[10] = (t_op){"st", 2, {T_REG, T_IND | T_REG}, 3, 1, 2};
	op_tab[3] = (t_op){"add", 3, {T_REG, T_REG, T_REG}, 4, 1, 4};
	op_tab[4] = (t_op){"sub", 3, {T_REG, T_REG, T_REG}, 5, 1, 4};
	op_tab[5] = (t_op){"and", 3, {T_REG | T_DIR | T_IND, T_REG | T_IND \
		| T_DIR, T_REG}, 6, 1, 4};
	op_tab[6] = (t_op){"or", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND \
		| T_DIR, T_REG}, 7, 1, 4};
	op_tab[7] = (t_op){"xor", 3, {T_REG | T_IND | T_DIR, T_REG | T_IND \
		| T_DIR, T_REG}, 8, 1, 4};
	op_tab[8] = (t_op){"zjmp", 1, {T_DIR}, 9, 0, 2};
	op_tab[1] = (t_op){"ldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, \
		T_REG}, 10, 1, 2};
	op_tab[2] = (t_op){"sti", 3, {T_REG, T_REG | T_DIR | T_IND, T_DIR \
		| T_REG}, 11, 1, 2};
	op_tab[11] = (t_op){"fork", 1, {T_DIR}, 12, 0, 2};
	op_tab[13] = (t_op){"lld", 2, {T_DIR | T_IND, T_REG}, 13, 1, 4};
	op_tab[12] = (t_op){"lldi", 3, {T_REG | T_DIR | T_IND, T_DIR | T_REG, \
		T_REG}, 14, 1, 2};
	op_tab[14] = (t_op){"lfork", 1, {T_DIR}, 15, 0, 2};
	op_tab[15] = (t_op){"aff", 1, {T_REG}, 16, 1, 2};
	op_tab[16] = (t_op){0, 0, {0}, 0, 0, 0};
}

t_op			*asm_sgl_inst(void)
{
	static t_op		op_tab[17];

	if (!op_tab[0].name)
		asm_init_sgl(op_tab);
	return (op_tab);
}

static size_t	asm_update_inst(t_file_h *file_h, t_prog *prog, int code)
{
	t_op			*op_tab;
	t_inst			*fresh;

	op_tab = asm_sgl_inst();
	if (!(fresh = (t_inst *)ft_memalloc(sizeof(*fresh))))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	fresh->num_line = prog->num_line;
	fresh->infos = op_tab[code];
	fresh->addr = prog->header.size;
	fresh->header = &prog->inst_h;
	prog->header.size += fresh->infos.ocp + 1;
	if (!prog->inst_h.head)
	{
		fresh->prev = NULL;
		prog->inst_h.head = fresh;
		prog->inst_h.tail = fresh;
		return (ft_strlen(fresh->infos.name));
	}
	fresh->prev = prog->inst_h.tail;
	prog->inst_h.tail->next = fresh;
	prog->inst_h.tail = fresh;
	return (ft_strlen(fresh->infos.name));
}

void			asm_add_inst(t_file_h *file_h, t_prog *prog, char *s, int code)
{
	int				i;

	i = -1;
	s = asm_goto_start(s) + asm_update_inst(file_h, prog, code);
	if (!(prog->inst_h.tail->tab_args = ft_strsplit(s, CHAR_SEPAR)))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	asm_check_type(file_h, prog);
	while (prog->inst_h.tail->tab_args[++i])
		asm_add_arg(file_h, prog, prog->inst_h.tail->tab_args[i]);
}
