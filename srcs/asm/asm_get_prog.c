/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_prog.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 01:44:45 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/20 18:58:30 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static int		asm_is_label(char *line)
{
	size_t			index;

	line = asm_goto_start(line);
	index = ft_strspn(line, STR_LABEL);
	if (line[index] != CHAR_LABEL)
		return (0);
	return (1);
}

static int		asm_is_inst(char *line)
{
	t_op			*op_tab;
	int				i;

	i = -1;
	op_tab = asm_sgl_inst();
	line = asm_goto_start(line);
	while (op_tab[++i].name)
		if (ft_strnequ(line, op_tab[i].name, ft_strlen(op_tab[i].name)))
			return (i);
	return (-1);
}

void			asm_get_prog(t_file_h *file_h, t_prog *prog, t_file *tmp)
{
	int				code;
	char			*str;
	t_op			*op_tab;

	op_tab = asm_sgl_inst();
	while (tmp)
	{
		prog->num_line = tmp->num_line;
		str = asm_goto_start(tmp->line);
		if (str[0] && asm_is_label(str))
		{
			str = asm_add_label(file_h, prog, str);
			if (str[0] && (code = asm_is_inst(str)) != -1)
				asm_add_inst(file_h, prog, str, code);
			else if (code == -1 && asm_goto_start(str)[0])
				asm_error(ASM_ERROR_SYNTAX, file_h, prog, NULL);
		}
		else if (str[0] && (code = asm_is_inst(str)) != -1)
			asm_add_inst(file_h, prog, str, code);
		else if (str[0])
			asm_error(ASM_ERROR_SYNTAX, file_h, prog, NULL);
		tmp = tmp->next;
	}
	prog->header.size = asm_reverse_int(prog->header.size);
}
