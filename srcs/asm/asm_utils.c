/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 00:11:35 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/21 13:00:41 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "asm.h"

int				asm_get_arg_type(char *arg)
{
	if (arg[0] == CHAR_REGIST)
		return (T_REG);
	else if (arg[0] == CHAR_DIRECT)
		return (T_DIR);
	return (T_IND);
}

unsigned int	asm_reverse_int(unsigned int value)
{
	return (((value >> 24) & 0xff) | ((value << 8) & 0xff0000) | \
			((value >> 8) & 0xff00) | ((value << 24) & 0xff000000));
}

inline char		*asm_goto_start(char *str)
{
	return (str + ft_strspn(str, " \t\n\v\f\r"));
}

void			asm_write_num(t_file_h *file_h, t_prog *prog, int val, int len)
{
	if (!len)
		return ;
	asm_write_num(file_h, prog, val >> 8, len - 1);
	if (write(file_h->fd, &val, 1) == -1)
		asm_error(ASM_ERROR_WRITE, file_h, prog, NULL);
	if (file_h->opts & (1 << ASM_OPTS_P))
		asm_print_num(file_h, 0, (val & 0b11111111));
}

void			asm_print_num(t_file_h *file_h, int color, int val)
{
	if (color)
		ft_printf("%@", color);
	if (file_h->opts & (1 << ASM_OPTS_B))
		ft_printf("0b%.8b ", val);
	else
		ft_printf("0x%.2x ", val);
}
