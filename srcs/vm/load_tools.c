/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:04:07 by jayache           #+#    #+#             */
/*   Updated: 2019/03/09 15:44:39 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	load_in_reg(t_process *process, int nb, int val)
{
	if (nb <= 0 || nb > REG_NUMBER)
		error("Loading in a unexisting register", 0, 0, 0);
	process->regist[(nb - 1) % REG_NUMBER] = val;
}

void	write_in_mem(t_vm *vm, t_process *process, int pos, int to_write)
{
	char *arena;

	arena = vm->arena;
	arena[pos % MEM_SIZE] = (to_write & FIRST_CHAR_INT_MASK) >> 24;
	arena[(pos + 1) % MEM_SIZE] = (to_write & SECOND_CHAR_INT_MASK) >> 16;
	arena[(pos + 2) % MEM_SIZE] = (to_write & THIRD_CHAR_INT_MASK) >> 8;
	arena[(pos + 3) % MEM_SIZE] = (to_write & FOURTH_CHAR_INT_MASK);
	vm->info_arena[pos % MEM_SIZE] = process->player_id;
	vm->info_arena[(pos + 1) % MEM_SIZE] = process->player_id;
	vm->info_arena[(pos + 2) % MEM_SIZE] = process->player_id;
	vm->info_arena[(pos + 3) % MEM_SIZE] = process->player_id;
}
