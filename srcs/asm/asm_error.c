/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_error.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 04:47:38 by lbrangie          #+#    #+#             */
/*   Updated: 2019/03/10 14:33:56 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static char		**asm_get_error_tab(void)
{
	static char		*tab[14] = {
		ASM_MSG_USAGE,
		AMS_MSG_EMPTY,
		ASM_MSG_MALLOC,
		ASM_MSG_NAME,
		ASM_MSG_SYNTAX,
		ASM_MSG_COMMAND,
		ASM_MSG_PNAME,
		ASM_MSG_PCOMM,
		ASM_MSG_ARGS,
		ASM_MSG_LABEL,
		ASM_MSG_OPEN,
		AMS_MSG_WRITE,
		ASM_MSG_CLOSE,
		NULL
	};

	return (tab);
}

static char		*asm_error_line(unsigned int num, t_file_h *file_h)
{
	t_file			*tmp;

	tmp = file_h->head;
	while (tmp)
	{
		if (num == tmp->num_line)
			return (tmp->line);
		tmp = tmp->next;
	}
	return (NULL);
}

void			asm_error(int num, t_file_h *file_h, t_prog *prog, void *ptr)
{
	char			*line;
	char			**error_tab;

	if (num == ASM_NO_ERROR)
		return ;
	error_tab = asm_get_error_tab();
	if (num == 5 || num == 9 || num == 10)
	{
		ft_fprintf(stderr, "Error (asm) ");
		if ((line = asm_error_line(prog->num_line, file_h)))
			ft_fprintf(stderr, "line %d --> %@[%s]%@", \
					prog->num_line, RED, line, EOC);
		ft_fprintf(stderr, "\n");
	}
	else
		ft_fprintf(stderr, "%s\n", error_tab[num - 1]);
	if (file_h)
		asm_del_file(file_h);
	if (prog)
		asm_del_prog(prog);
	ft_memdel(&ptr);
	exit(EXIT_FAILURE);
}
