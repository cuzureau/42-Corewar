/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_header.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 23:59:53 by lbrangie          #+#    #+#             */
/*   Updated: 2019/03/10 16:05:13 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		*asm_get_mult_lines(t_file_h *file_h, t_prog *prog, \
				t_file **tmp, char *str)
{
	char			*string;
	char			*garbage;

	if (!(string = ft_strjoin(str, "\n")))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	if (ft_strchr(string, '\"'))
		return (string);
	*tmp = (*tmp)->next;
	while (*tmp)
	{
		garbage = string;
		if (!(string = ft_strjoin(garbage, (*tmp)->line)))
			asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
		ft_strdel(&garbage);
		if (ft_strchr(string, '\"'))
			return (string);
		garbage = string;
		if (!(string = ft_strjoin(garbage, "\n")))
			asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
		ft_strdel(&garbage);
		*tmp = (*tmp)->next;
	}
	ft_strdel(&string);
	return (NULL);
}

static void		asm_get_prog_comm(t_file_h *file_h, t_prog *prog, t_file **tmp)
{
	char			*comment;
	char			*str;
	size_t			end;

	comment = NULL;
	str = (asm_goto_start((*tmp)->line) + ft_strlen(CMD_COMM));
	str = asm_goto_start(str);
	if (str[0] != '\"')
		asm_error(ASM_ERROR_PCOMM, file_h, prog, NULL);
	if (!(comment = asm_get_mult_lines(file_h, prog, tmp, str + 1)))
		asm_error(ASM_ERROR_PCOMM, file_h, prog, NULL);
	end = ft_strcspn(comment, "\"");
	comment[end] = '\0';
	end += ft_strspn(comment + end + 1, " \t\v\f\r\n");
	if (comment[end + 1] && comment[end + 1] != '\n')
		asm_error(ASM_ERROR_SYNTAX, file_h, prog, (void*)comment);
	if (!comment[0])
	{
		strcat(prog->header.comm, DFT_COMM);
		return ((void)ft_strdel(&comment));
	}
	if (ft_strlen(comment) > LEN_COMM)
		asm_error(ASM_ERROR_PCOMM, file_h, prog, (void*)comment);
	ft_strcat(prog->header.comm, comment);
	ft_strdel(&comment);
}

static void		asm_get_prog_name(t_file_h *file_h, t_prog *prog, t_file **tmp)
{
	char			*name;
	char			*str;
	size_t			end;

	name = NULL;
	str = (asm_goto_start((*tmp)->line) + ft_strlen(CMD_NAME));
	str = asm_goto_start(str);
	if (str[0] != '\"')
		asm_error(ASM_ERROR_PNAME, file_h, prog, NULL);
	if (!(name = asm_get_mult_lines(file_h, prog, tmp, str + 1)))
		asm_error(ASM_ERROR_PNAME, file_h, prog, NULL);
	end = ft_strcspn(name, "\"");
	name[end] = '\0';
	end += ft_strspn(name + end + 1, " \t\v\f\r\n");
	if (name[end + 1] && name[end + 1] != '\n')
		asm_error(ASM_ERROR_SYNTAX, file_h, prog, (void*)name);
	if (!name[0])
	{
		strcat(prog->header.name, DFT_NAME);
		return ((void)ft_strdel(&name));
	}
	if (ft_strlen(name) > LEN_NAME)
		asm_error(ASM_ERROR_PNAME, file_h, prog, (void*)name);
	ft_strcat(prog->header.name, name);
	ft_strdel(&name);
}

t_file			*asm_get_header(t_file_h *file_h, t_prog *prog)
{
	t_file			*tmp;
	char			*str;

	ft_bzero(prog, sizeof(t_prog));
	prog->header.magic = asm_reverse_int(COREWAR_EXEC_MAGIC);
	prog->header.size = 0;
	tmp = file_h->head;
	while (tmp && (str = asm_goto_start(tmp->line)) && ((!str[0] || \
		str[0] == CMD_NAME[0] || str[0] == CMD_COMM[0]) || str[0]))
	{
		if (prog->header.name[0] && prog->header.comm[0])
			return (tmp);
		if (ft_strnequ(str, CMD_NAME, ft_strlen(CMD_NAME)))
			asm_get_prog_name(file_h, prog, &tmp);
		else if (ft_strnequ(str, CMD_COMM, ft_strlen(CMD_COMM)))
			asm_get_prog_comm(file_h, prog, &tmp);
		else if (str[0])
			asm_error(ASM_ERROR_COMMAND, file_h, prog, NULL);
		tmp = tmp->next;
	}
	return (NULL);
}
