/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asm.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 18:34:33 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/21 13:10:23 by cuzureau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ASM_H
# define ASM_H

# include "libft.h"
# include "ft_printf.h"
# include "asm_defines.h"
# include "asm_typedefs.h"

/*
**	asm.c
*/
int				main(int ac, char **av);

/*
**	asm_add_arg.c
*/
void			asm_check_type(t_file_h *file_h, t_prog *prog);
void			asm_add_arg(t_file_h *file_h, t_prog *prog, char *arg);

/*
**	asm_add_inst.c
*/
t_op			*asm_sgl_inst(void);
void			asm_add_inst(t_file_h *file_h, t_prog *prog, char *s, int code);

/*
**	asm_add_label.c
*/
char			*asm_add_label(t_file_h *file_h, t_prog *prog, char *line);

/*
**	asm_check_label.c
*/
void			asm_check_label(t_file_h *file_h, t_prog *prog);

/*
**	asm_del_data.c
*/
void			asm_del_file(t_file_h *file_h);
void			asm_del_prog(t_prog *prog);

/*
**	asm_error.c
*/
void			asm_error(int num, t_file_h *file_h, t_prog *prog, void *ptr);

/*
**	asm_get_file.c
*/
void			asm_get_file(t_file_h *file_h, char *name);

/*
**	asm_get_header.c
*/
t_file			*asm_get_header(t_file_h *file_h, t_prog *prog);

/*
**	asm_get_prog.c
*/
void			asm_get_prog(t_file_h *file_h, t_prog *prog, t_file *tmp);

/*
**	asm_print.c
*/
void			asm_put_prog(t_prog *prog);
void			asm_put_file(t_file_h *file_h);

/*
**	asm_utils.c
*/
int				asm_get_arg_type(char *arg);
unsigned int	asm_reverse_int(unsigned int value);
char			*asm_goto_start(char *str);
void			asm_write_num(t_file_h *file_h, t_prog *prog, int val, int len);
void			asm_print_num(t_file_h *file_h, int color, int val);

/*
**	asm_write_output.c
*/
void			asm_write_output(t_file_h *file_h, t_prog *prog);

#endif
