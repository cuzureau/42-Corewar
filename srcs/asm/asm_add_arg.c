/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_add_arg.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:42:43 by cuzureau          #+#    #+#             */
/*   Updated: 2019/03/10 16:26:08 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

void			asm_check_type(t_file_h *file_h, t_prog *prog)
{
	int				i;
	char			*str;
	t_inst			*last;

	last = prog->inst_h.tail;
	if (ft_tablen(last->tab_args) != last->infos.nb_args)
		asm_error(ASM_ERROR_ARGS, file_h, prog, NULL);
	i = -1;
	while (last->tab_args[++i])
	{
		str = asm_goto_start(last->tab_args[i]);
		if (!(last->infos.args[i] & asm_get_arg_type(str)))
			asm_error(ASM_ERROR_ARGS, file_h, prog, NULL);
	}
}

static int		asm_get_arg_size(t_inst *inst, t_arg *arg)
{
	if (arg->type == T_REG)
		return (1);
	else if (arg->type == T_IND \
		|| (arg->type == T_DIR && inst->infos.dir_size == 2))
		return (2);
	return (4);
}

static int		asm_check_num(t_arg *fresh)
{
	char			*str;
	int				i;

	str = fresh->str;
	if (fresh->type == T_DIR || fresh->type == T_REG)
		str++;
	if (!*str)
		return (1);
	if (*str == '-')
		str++;
	if (!*str)
		return (1);
	i = -1;
	while (str[++i])
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			return (1);
	return (0);
}

static void		asm_is_arg_valid(t_file_h *file_h, t_prog *prog, t_arg *fresh)
{
	if (!ft_strchr(fresh->str, CHAR_LABEL) \
		&& (fresh->type == T_DIR || fresh->type == T_IND))
		if (asm_check_num(fresh))
			asm_error(ASM_ERROR_SYNTAX, file_h, prog, NULL);
	if (!ft_strchr(fresh->str, CHAR_LABEL) \
		&& fresh->type == T_REG)
		if (asm_check_num(fresh))
			asm_error(ASM_ERROR_SYNTAX, file_h, prog, NULL);
	if (ft_strchr(fresh->str, CHAR_LABEL))
	{
		if (fresh->str[ft_strcspn(fresh->str, " \t\n\r\v\f")] != '\0')
			asm_error(ASM_ERROR_SYNTAX, file_h, prog, NULL);
		fresh->label = 1;
	}
}

void			asm_add_arg(t_file_h *file_h, t_prog *prog, char *arg)
{
	t_arg			*fresh;
	t_arg			*tmp;

	if (!(fresh = (t_arg *)ft_memalloc(sizeof(*fresh))))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	if (!(fresh->str = ft_strtrim(asm_goto_start(arg))))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	fresh->type = asm_get_arg_type(fresh->str);
	fresh->size = asm_get_arg_size(prog->inst_h.tail, fresh);
	fresh->next = NULL;
	prog->header.size += fresh->size;
	if (!prog->inst_h.tail->arg)
	{
		prog->inst_h.tail->arg = fresh;
		asm_is_arg_valid(file_h, prog, fresh);
		return ;
	}
	tmp = prog->inst_h.tail->arg;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = fresh;
	asm_is_arg_valid(file_h, prog, fresh);
}
