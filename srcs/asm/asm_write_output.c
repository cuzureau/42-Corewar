/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_write_output.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 00:58:01 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/20 15:37:41 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_write_arg(t_file_h *file_h, t_prog *prog, t_inst *inst)
{
	int				i;
	t_arg			*tmp;

	i = 0;
	tmp = inst->arg;
	while (tmp)
	{
		if (file_h->opts & (1 << ASM_OPTS_P))
			ft_printf("%@", RED + i);
		if (tmp->type == T_REG)
			asm_write_num(file_h, prog, ft_atoi(tmp->str + 1), tmp->size);
		else if (tmp->type == T_DIR && tmp->label == -1)
			asm_write_num(file_h, prog, ft_atoi(tmp->str + 1), tmp->size);
		else if (tmp->type == T_DIR && tmp->label != -1)
			asm_write_num(file_h, prog, (tmp->label - inst->addr), tmp->size);
		else if (tmp->type == T_IND && tmp->label == -1)
			asm_write_num(file_h, prog, ft_atoi(tmp->str), tmp->size);
		else if (tmp->type == T_IND && tmp->label != -1)
			asm_write_num(file_h, prog, (tmp->label - inst->addr), tmp->size);
		if (file_h->opts & (1 << ASM_OPTS_P))
			ft_printf("%@", EOC);
		tmp = tmp->next;
		i++;
	}
}

static void		asm_write_ocp(t_file_h *file_h, t_prog *prog, t_inst *inst)
{
	int				i;
	int				ocp;
	t_arg			*tmp;

	i = 2;
	ocp = 0;
	tmp = inst->arg;
	while (tmp)
	{
		if (tmp->type == T_REG)
			ocp |= (0b01 << (8 - i));
		else if (tmp->type == T_DIR)
			ocp |= (0b10 << (8 - i));
		else if (tmp->type == T_IND)
			ocp |= (0b11 << (8 - i));
		i += 2;
		tmp = tmp->next;
	}
	if (write(file_h->fd, &ocp, 1) == -1)
		asm_error(ASM_ERROR_WRITE, file_h, prog, NULL);
	if (file_h->opts & (1 << ASM_OPTS_P))
		asm_print_num(file_h, MAGENTA, ocp);
}

static void		asm_write_instruction(t_file_h *file_h, t_prog *prog)
{
	t_inst			*tmp;

	tmp = prog->inst_h.head;
	while (tmp)
	{
		if (write(file_h->fd, &tmp->infos.opcode, 1) == -1)
			asm_error(ASM_ERROR_WRITE, file_h, prog, NULL);
		if (file_h->opts & (1 << ASM_OPTS_P))
			asm_print_num(file_h, CYAN, tmp->infos.opcode);
		if (tmp->infos.ocp)
			asm_write_ocp(file_h, prog, tmp);
		asm_write_arg(file_h, prog, tmp);
		if (file_h->opts & (1 << ASM_OPTS_P))
			ft_printf("%@\n", EOC);
		tmp = tmp->next;
	}
}

void			asm_write_output(t_file_h *file_h, t_prog *prog)
{
	if (!(file_h->dst_name = ft_strjoin(file_h->file_name, EXT_DST)))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	if ((file_h->fd = open(file_h->dst_name, \
		O_WRONLY | O_APPEND | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR)) == -1)
		asm_error(ASM_ERROR_OPEN, file_h, prog, NULL);
	if (write(file_h->fd, &prog->header, sizeof(prog->header)) == -1)
		asm_error(ASM_ERROR_WRITE, file_h, prog, NULL);
	asm_write_instruction(file_h, prog);
	if (close(file_h->fd) == -1)
		asm_error(ASM_ERROR_CLOSE, file_h, prog, NULL);
}
