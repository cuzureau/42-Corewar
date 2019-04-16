/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/11 16:56:45 by jayache           #+#    #+#             */
/*   Updated: 2019/03/10 17:31:35 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** EXECUTES ZJMP
*/

void	execute_and(t_vm *vm, t_process *process)
{
	int	a;
	int b;

	if (!load_and(vm, process))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	a = get_arg_value(process, process->arg, 0);
	b = get_arg_value(process, process->arg, 1);
	load_in_reg(process, process->arg.param[2], a & b);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		ft_printf("P %4d | and %d %d", process->id, a, b);
		ft_printf(" r%d\n", process->arg.param[2]);
	}
	process->carry = (a & b) == 0;
	move_process(vm, process, process->arg.size);
	process->cycle = -1;
}

/*
** EXECUTES ADD
*/

void	execute_add(t_vm *vm, t_process *process)
{
	int a;
	int b;

	if (!load_add(vm, process))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	a = read_from_reg(process, process->arg.param[0]);
	b = read_from_reg(process, process->arg.param[1]);
	load_in_reg(process, process->arg.param[2], a + b);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
		p_arg("add", process->id, process->arg);
	move_process(vm, process, process->arg.size);
	process->carry = (a + b) == 0;
	process->cycle = -1;
}

/*
** EXECUTES SUB
*/

void	execute_sub(t_vm *vm, t_process *process)
{
	int a;
	int b;

	if (!(load_sub(vm, process)))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	a = read_from_reg(process, process->arg.param[0]);
	b = read_from_reg(process, process->arg.param[1]);
	load_in_reg(process, process->arg.param[2], a - b);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
		p_arg("sub", process->id, process->arg);
	move_process(vm, process, process->arg.size);
	process->carry = (a - b) == 0;
	process->cycle = -1;
}

/*
** EXECUTES FORK
*/

void	execute_fork(t_vm *vm, t_process *process)
{
	t_process *f;

	load_fork(vm, process);
	f = clone(vm, process);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		ft_printf("P %4d | fork %d (%d)\n", process->id, process->arg.param[0],
				convert_pos(process, process->arg.param[0]));
	}
	f->pc = convert_pos(process, process->arg.param[0]);
	add_process(vm, f);
	move_process(vm, process, 3);
	process->cycle = -1;
}

/*
** EXECUTES LDI
** LDI ADDS TOGETHER THE TWO FIRST ARGS, AND THEN READS IN THE ARENA AN INT
** AT THAT POSITION
*/

void	execute_ldi(t_vm *vm, t_process *process)
{
	int	a;
	int	r1;
	int r2;

	if (!(load_ldi(vm, process)))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	r1 = read_arg_val(process, 0);
	r2 = read_arg_val(process, 1);
	a = read_from_mem(vm, convert_pos(process, r1 + r2));
	load_in_reg(process, process->arg.param[2], a);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		ft_printf("P %4d | ldi %d %d r%d\n", process->id, r1,
				r2, process->arg.param[2]);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				r1, r2, r1 + r2, convert_pos(process, r1 + r2));
	}
	move_process(vm, process, process->arg.size);
	process->cycle = -1;
}
