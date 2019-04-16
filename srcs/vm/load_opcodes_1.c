/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_opcodes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 19:40:24 by jayache           #+#    #+#             */
/*   Updated: 2019/03/04 14:16:17 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** LOADS LD AND RETURNS 0 IF IT ISN'T VALID
** LD MUST HAVE TWO ARGS, A VALUE (IND/DIR) AND A REGISTER
*/

int	load_ld(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (valid_arg_nb(process->arg) != 2)
		return (0);
	if ((process->arg.type[0] == DIR_CODE || process->arg.type[0] == IND_CODE)
			&& process->arg.type[1] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS ST AND RETURNS 0 IF IT ISN'T VALID
** ST MUST HAVE TWO ARGS, A REGISTER AND AN INDEX (REG/IND)
*/

int	load_st(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 2);
	if (valid_arg_nb(process->arg) != 2)
		return (0);
	if ((process->arg.type[1] == REG_CODE || process->arg.type[1] == IND_CODE)
			&& process->arg.type[0] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS LIVE
** LIVE CANNOT FAIL
*/

int	load_live(t_vm *vm, t_process *process)
{
	ft_bzero(&process->arg, sizeof(t_arg));
	process->arg.opcode = LIVE;
	process->arg.param[0] = arg_size_4(vm->arena, process->pc + 1);
	return (1);
}

/*
** LOADS STI AND RETURNS 0 IF IT ISN'T VALID
*/

int	load_sti(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 2);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (arg_is(process->arg.type[1], DIR_CODE, REG_CODE)
			&& process->arg.type[0] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS ZJMP AND PREPARE THE PROCESS FOR IT
** ZJMP CANNOT FAIL
*/

int	load_zjmp(t_vm *vm, t_process *process)
{
	ft_bzero(&process->arg, sizeof(t_arg));
	process->arg.opcode = ZJMP;
	process->arg.param[0] = arg_size_2(vm->arena, process->pc + 1);
	return (1);
}
