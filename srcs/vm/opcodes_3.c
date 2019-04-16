/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes_3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/23 15:42:11 by jayache           #+#    #+#             */
/*   Updated: 2019/03/09 16:01:55 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	execute_lldi(t_vm *vm, t_process *process)
{
	int	a;
	int	b;
	int	c;

	if (!(load_lldi(vm, process)))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	b = process->arg.param[0];
	c = process->arg.param[1];
	if (process->arg.type[0] == PARAM_REGISTER)
		a = read_from_reg(process, b + c);
	else
		a = read_from_mem(vm, convert_pos_long(process, b + c));
	load_in_reg(process, process->arg.param[2], a);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		p_arg("lldi", process->id, process->arg);
		ft_printf("       | -> load from %d + %d = %d (with pc and mod %d)\n",
				b, c, b + c, convert_pos(process, b + c));
	}
	move_process(vm, process, process->arg.size);
	process->carry = 1;
	process->cycle = -1;
}

/*
** EXECUTES LFORK
*/

void	execute_lfork(t_vm *vm, t_process *process)
{
	t_process *f;

	load_lfork(vm, process);
	f = clone(vm, process);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		ft_printf("P %4d | lfork %d (%d)\n", process->id, process->arg.param[0],
				convert_pos_long_print(process, process->arg.param[0]));
	}
	f->pc = convert_pos_long(process, process->arg.param[0]);
	add_process(vm, f);
	move_process(vm, process, 3);
	process->cycle = -1;
}

/*
** EXECUTES XOR
*/

void	execute_xor(t_vm *vm, t_process *process)
{
	int	a;
	int b;

	if (!(load_xor(vm, process)))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	a = get_arg_value(process, process->arg, 0);
	b = get_arg_value(process, process->arg, 1);
	load_in_reg(process, process->arg.param[2], a ^ b);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		ft_printf("P %4d | xor %d %d", process->id, a, b);
		ft_printf(" r%d\n", process->arg.param[2]);
	}
	process->carry = (process->arg.param[0] == 0);
	process->carry = (a ^ b) == 0;
	move_process(vm, process, process->arg.size);
}

/*
** EXECUTES OR
*/

void	execute_or(t_vm *vm, t_process *process)
{
	int	a;
	int b;

	if (!load_or(vm, process))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	a = get_arg_value(process, process->arg, 0);
	b = get_arg_value(process, process->arg, 1);
	load_in_reg(process, process->arg.param[2], a | b);
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
	{
		ft_printf("P %4d | or %d %d", process->id, a, b);
		ft_printf(" r%d\n", process->arg.param[2]);
	}
	process->carry = (process->arg.param[0] == 0);
	process->carry = (a | b) == 0;
	move_process(vm, process, process->arg.size);
}

void	execute_aff(t_vm *vm, t_process *process)
{
	if (!load_aff(vm, process))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
		ft_printf("P %4d | aff %d\n", process->id, process->arg.param[0]);
	if (vm->visu == 0)
		ft_printf("%c\n", process->arg.param[0] % 256);
	move_process(vm, process, process->arg.size);
}
