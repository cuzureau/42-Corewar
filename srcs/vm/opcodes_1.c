/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes_1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:41:52 by jayache           #+#    #+#             */
/*   Updated: 2019/03/10 17:31:46 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** EXECUTES A LD
*/

void	execute_ld(t_vm *vm, t_process *process)
{
	int		a;
	int		b;

	if (!load_ld(vm, process))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	if (process->arg.type[0] == IND_CODE)
		a = read_from_mem(vm, convert_pos(process, process->arg.param[0]));
	else
		a = process->arg.param[0];
	b = process->arg.param[1];
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
		ft_printf("P %4d | ld %d r%d\n", process->id, a, b);
	load_in_reg(process, process->arg.param[1], a);
	move_process(vm, process, process->arg.size);
	process->carry = a == 0;
	process->cycle = -1;
}

/*
** EXECUTES ST
*/

void	execute_st(t_vm *vm, t_process *process)
{
	int	a;

	if (!load_st(vm, process))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	a = read_from_reg(process, process->arg.param[0]);
	if (process->arg.type[1] == PARAM_REGISTER)
		load_in_reg(process, process->arg.param[1], a);
	else
		write_in_mem(vm, process, convert_pos(process, process->arg.param[1]),
				a);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
		p_arg("st", process->id, process->arg);
	move_process(vm, process, process->arg.size);
	process->cycle = -1;
}

/*
** EXECUTES LIVE
** NOTIFY THE VM THAT THE PLAYER AND THE PROCESSES ARE ALIVE
*/

void	execute_live(t_vm *vm, t_process *process)
{
	load_live(vm, process);
	if (verbose_level(vm, DEBUG_PRINT_LIVES))
		ft_printf("P %4d | live %d\n", process->id, process->arg.param[0]);
	live(vm, process->arg.param[0]);
	move_process(vm, process, 5);
	process->last_live = vm->cycle;
	process->lives += 1;
	process->cycle = -1;
}

/*
** EXECUTES STI
** WRITES IN THE MEMORY
*/

void	execute_sti(t_vm *vm, t_process *p)
{
	int		a;
	int		b;
	int		c;

	if (!load_sti(vm, p))
	{
		move_process(vm, p, skip_invalid_arg(p->arg));
		return ;
	}
	a = read_from_reg(p, p->arg.param[0]);
	b = read_arg_val(p, 1);
	c = read_arg_val(p, 2);
	write_in_mem(vm, p, convert_pos(p, b + c), a);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		if ((p->arg.type[1] != REG_CODE || p->arg.type[2] != REG_CODE)
				|| (p->arg.type[1] == REG_CODE && p->arg.type[2] == REG_CODE))
			ft_printf("P %4d | sti r%d %d %d\n", p->id, p->arg.param[0], b, c);
		else
			p_arg("sti", p->id, p->arg);
		ft_printf("       | -> store to %d + %d = %d (with pc and mod %d)\n", b,
				c, b + c, convert_pos_print(p, b + c));
	}
	move_process(vm, p, p->arg.size);
	p->cycle = -1;
}

/*
** EXECUTES ZJMP
*/

void	execute_zjmp(t_vm *vm, t_process *process)
{
	load_zjmp(vm, process);
	if (process->carry)
	{
		if (verbose_level(vm, DEBUG_PRINT_EXEC))
			ft_printf("P %4d | zjmp %d OK\n", process->id,
					process->arg.param[0]);
		process->pc = convert_pos(process, process->arg.param[0]);
	}
	else
	{
		if (verbose_level(vm, DEBUG_PRINT_EXEC))
			ft_printf("P %4d | zjmp %d FAILED\n", process->id,
					process->arg.param[0]);
		move_process(vm, process, 3);
	}
	process->cycle = -1;
}
