/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute_opcode.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:11:45 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 13:37:15 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** PART TWO OF THE WRAPPER
*/

static void	load_next_instruction_2(t_process *process, unsigned char code)
{
	if (code == ZJMP)
		process->cycle = 20;
	else if (code == AND)
		process->cycle = 6;
	else if (code == OR)
		process->cycle = 6;
	else if (code == XOR)
		process->cycle = 6;
	else if (code == ADD)
		process->cycle = 10;
	else if (code == SUB)
		process->cycle = 10;
	else if (code == FORK)
		process->cycle = 800;
	else if (code == LFORK)
		process->cycle = 1500;
	else if (code == LDI)
		process->cycle = 25;
	else if (code == LLDI)
		process->cycle = 50;
}

/*
** WRAPPER FUNCTION FOR LOAD_xx
*/

void		load_next_instruction(t_vm *vm, t_process *process)
{
	unsigned char code;

	code = (unsigned char)vm->arena[process->pc % MEM_SIZE];
	if (!process->player_id)
		process->player_id = vm->info_arena[process->pc % MEM_SIZE];
	process->arg.opcode = code;
	if (code > 16 || !code)
		process->cycle = 1;
	else if (code == LIVE)
		process->cycle = 10;
	else if (code == LD)
		process->cycle = 5;
	else if (code == ST)
		process->cycle = 5;
	else if (code == STI)
		process->cycle = 25;
	else if (code == AFF)
		process->cycle = 2;
	else if (code == LLD)
		process->cycle = 10;
	else
		load_next_instruction_2(process, code);
}

/*
** PART TWO OF THE WRAPPER
*/

static void	execute_instruction_2(t_vm *vm, t_process *process,
		unsigned char code)
{
	if (code == AND)
		execute_and(vm, process);
	else if (code == OR)
		execute_or(vm, process);
	else if (code == XOR)
		execute_xor(vm, process);
	else if (code == ADD)
		execute_add(vm, process);
	else if (code == SUB)
		execute_sub(vm, process);
	else if (code == FORK)
		execute_fork(vm, process);
	else if (code == LFORK)
		execute_lfork(vm, process);
	else if (code == LDI)
		execute_ldi(vm, process);
	else if (code == LLDI)
		execute_lldi(vm, process);
	else if (code == AFF)
		execute_aff(vm, process);
}

/*
** WRAPPER FUNCTION FOR EXECUTE_xx
*/

void		execute_instruction(t_vm *vm, t_process *process)
{
	unsigned char code;

	code = process->arg.opcode;
	if (code > 16 || code == 0)
	{
		process->cycle = -1;
		process->pc++;
	}
	else if (code == LIVE)
		execute_live(vm, process);
	else if (code == LD)
		execute_ld(vm, process);
	else if (code == ST)
		execute_st(vm, process);
	else if (code == STI)
		execute_sti(vm, process);
	else if (code == ZJMP)
		execute_zjmp(vm, process);
	else if (code == LLD)
		execute_ld(vm, process);
	else
		execute_instruction_2(vm, process, code);
}
