/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_opcodes_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 17:00:18 by jayache           #+#    #+#             */
/*   Updated: 2019/03/10 17:31:28 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** LOADS AND AND RETURN 0 IF IT IS INVALID
** AND NEEDS THREE ARGS, TWO VALUES (CAN BE ANYTHING) AND A REGISTER
*/

int		load_and(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (process->arg.type[2] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS ADD AND PREPARE THE PROCESS FOR IT
** ADD NEEDS THREE ARGS, THEY ARE ALL REGISTERS
*/

int		load_add(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (process->arg.type[2] == REG_CODE && process->arg.type[1] == REG_CODE
			&& process->arg.type[0] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS SUB AND PREPARE THE PROCESS FOR IT
** SUB NEEDS THREE ARGS, THEY ARE ALL REGISTERS
*/

int		load_sub(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (process->arg.type[2] == REG_CODE && process->arg.type[1] == REG_CODE
			&& process->arg.type[0] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS FORK AND PREPARE THE PROCESS FOR IT
** FORK CANNOT FAIL
*/

int		load_fork(t_vm *vm, t_process *process)
{
	ft_bzero(&process->arg, sizeof(t_arg));
	process->arg.opcode = vm->arena[process->pc];
	process->arg.param[0] = arg_size_2(vm->arena, process->pc + 1);
	return (1);
}

/*
** LOADS LDI AND PREPARE THE PROCESS FOR IT
** LDI NEEDS THREE ARGS, AN INDEX (ANY), ANOTHER INDEX (IND/DIR) AND A REGISTER
*/

int		load_ldi(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 2);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (process->arg.type[2] == REG_CODE && arg_is(process->arg.type[1],
				REG_CODE, DIR_CODE))
		return (1);
	return (0);
}
