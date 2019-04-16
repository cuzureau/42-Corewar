/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_get_file.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 04:57:13 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/21 11:11:58 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

static void		asm_update_file(t_file_h *file_h, char *line)
{
	static int		id;
	t_file			*fresh;

	if (!(fresh = (t_file *)ft_memalloc(sizeof(*fresh))))
		asm_error(ASM_ERROR_MALLOC, file_h, NULL, NULL);
	if (!(fresh->line = ft_strndup(line, ft_strchr(line, CHAR_COMM) - line)))
		asm_error(ASM_ERROR_MALLOC, file_h, NULL, NULL);
	fresh->header = file_h;
	fresh->next = NULL;
	if (!file_h->head)
	{
		fresh->prev = NULL;
		fresh->num_line = 1;
		file_h->head = fresh;
		file_h->tail = fresh;
		return ;
	}
	fresh->num_line = ++id;
	fresh->prev = file_h->tail;
	file_h->tail->next = fresh;
	file_h->tail = fresh;
}

static int		asm_check_line(char *line)
{
	int				i;

	i = -1;
	while (line[0] && line[++i])
		if (line[i] < ' ' && !ft_isspace(line[i]) && !(line[i] & 0x10000000))
			return (1);
	return (0);
}

void			asm_get_file(t_file_h *file_h, char *name)
{
	char			*line;
	size_t			ext_len;

	line = NULL;
	ext_len = ft_strlen(EXT_SRC);
	if (ft_strlen(name) < ext_len || \
		!ft_strequ(ft_strrchr(name, EXT_SRC[0]), EXT_SRC))
		asm_error(ASM_ERROR_NAME, file_h, NULL, NULL);
	if (!(file_h->file_name = ft_strndup(name, ft_strlen(name) - ext_len)))
		asm_error(ASM_ERROR_MALLOC, file_h, NULL, NULL);
	if ((file_h->fd = open(name, O_RDONLY)) == -1)
		asm_error(ASM_ERROR_OPEN, file_h, NULL, NULL);
	if (read(file_h->fd, line, 0) == -1)
		asm_error(ASM_ERROR_OPEN, file_h, NULL, NULL);
	while (get_next_line(file_h->fd, &line) == 1)
	{
		if (asm_check_line(line))
			asm_error(ASM_ERROR_OPEN, file_h, NULL, NULL);
		if (asm_goto_start(line)[0] != CHAR_COMM)
			asm_update_file(file_h, line);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(file_h->fd) == -1)
		asm_error(ASM_ERROR_CLOSE, file_h, NULL, NULL);
}
