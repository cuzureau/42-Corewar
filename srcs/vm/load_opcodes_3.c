/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_opcodes_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:50:43 by jayache           #+#    #+#             */
/*   Updated: 2019/03/10 17:57:35 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** LOADS LLDI AND PREPARE THE PROCESS FOR IT
** LLDI NEEDS THREE ARGS, AN INDEX (ANY), ANOTHER INDEX (DIR/IND) AND A REGISTER
*/

int	load_lldi(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 2);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (arg_is(process->arg.type[1], IND_CODE, DIR_CODE)
			&& process->arg.type[2] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS LFORK AND PREPARE THE PROCESS FOR IT
** LFORK CANNOT FAIL
*/

int	load_lfork(t_vm *vm, t_process *process)
{
	ft_bzero(&process->arg, sizeof(t_arg));
	process->arg.opcode = vm->arena[process->pc];
	process->arg.param[0] = arg_size_2(vm->arena, process->pc + 1);
	return (1);
}

/*
** LOADS XOR AND PREPARE THE PROCESS FOR IT
** XOR NEEDS THREE ARGS, TWO VALUES (ANY) AND A REGISTER
*/

int	load_xor(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (process->arg.type[2] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS OR AND PREPARE THE PROCESS FOR IT
** OR NEEDS THREE ARGS, TWO VALUES (ANY) AND A REGISTER
*/

int	load_or(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (valid_arg_nb(process->arg) != 3)
		return (0);
	if (process->arg.type[2] == REG_CODE)
		return (1);
	return (0);
}

/*
** LOADS AFF
** AFF NEEDS ONE ARG, A REGISTER
*/

int	load_aff(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (!(process->arg.param[0] = read_from_reg(process, process->arg.param[0]
					% REG_NUMBER)))
		return (0);
	return (1);
}
