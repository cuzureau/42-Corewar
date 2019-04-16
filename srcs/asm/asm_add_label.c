/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_add_label.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cuzureau <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/14 21:21:09 by cuzureau          #+#    #+#             */
/*   Updated: 2019/02/20 19:00:06 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

char			*asm_add_label(t_file_h *file_h, t_prog *prog, char *line)
{
	char			*char_label;
	t_label			*fresh;
	t_label			*tmp;

	if (!(fresh = (t_label *)ft_memalloc(sizeof(*fresh))))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	line = asm_goto_start(line);
	char_label = ft_strchr(line, CHAR_LABEL);
	if (!(fresh->name = ft_strndup(line, char_label - line)))
		asm_error(ASM_ERROR_MALLOC, file_h, prog, NULL);
	if (fresh->name[0] == '\0')
		asm_error(ASM_ERROR_SYNTAX, file_h, prog, NULL);
	fresh->num_line = prog->num_line;
	fresh->addr = prog->header.size;
	fresh->next = NULL;
	if (!prog->label)
	{
		prog->label = fresh;
		return (char_label + 1);
	}
	tmp = prog->label;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = fresh;
	return (char_label + 1);
}
