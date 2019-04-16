/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:58:41 by jayache           #+#    #+#             */
/*   Updated: 2019/03/03 15:31:18 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** CONVERT AN ARGUMENT WHILE PROTECTING IT FROM UNDERFLOW
** IF CODE IN MACRO WAS ALLOWED, THIS WOULD BE IT
*/

int		convert_pos(t_process *process, int val)
{
	int t;

	t = ((process->pc + (val % IDX_MOD)) % MEM_SIZE);
	if (t < 0)
		t += MEM_SIZE;
	return (t);
}

/*
** SAME AS ABOVE WITHOUT THE UNDERFLOW, USED FOR PRINTING PURPOSES
*/

int		convert_pos_print(t_process *process, int val)
{
	int t;

	t = ((process->pc + (val % IDX_MOD)));
	return (t);
}

/*
** CONVERT AN ARGUMENT BLABLA
** IF CODE IN MACRO WAS ALLOWED, THIS WOULD BE IT
** SAME AS BEFORE WITHOUT % IDX_MOD
*/

int		convert_pos_long(t_process *process, int val)
{
	int t;

	t = ((process->pc + (val)) % MEM_SIZE);
	if (t < 0)
		t += MEM_SIZE;
	return (t);
}

/*
** SAME AS ABOVE WITHOUT THE UNDERFLOW, USED FOR PRINTING PURPOSES
*/

int		convert_pos_long_print(t_process *process, int val)
{
	int t;

	t = ((process->pc + (val)));
	return (t);
}

/*
** MOVE A PROCESS AND TAKE CARE TO ADJUST THE POSITION
*/

void	move_process(t_vm *vm, t_process *process, int l)
{
	int	temp;

	temp = process->pc;
	process->pc += l;
	if (process->pc < 0)
		process->pc += MEM_SIZE;
	process->pc %= MEM_SIZE;
	if (verbose_level(vm, DEBUG_PRINT_MOVE))
	{
		ft_printf("ADV %d (", l);
		if (process->pc == l)
			ft_printf("0x0000 -> ");
		else
			ft_printf("%#.4x -> ", (unsigned int)(temp));
		if (process->pc == 0)
			ft_printf("0x0000) ");
		else
			ft_printf("%#.4x) ", (unsigned int)(temp + l));
		print_mem_chunk(vm, temp, l);
		ft_printf(" \n");
	}
}
