/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   opcodes_4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:46:56 by jayache           #+#    #+#             */
/*   Updated: 2019/03/09 15:45:02 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** EXECUTES LLD
** READS AN INTEGER IN THE MEM, AND STORE IT IN A REGISTER
** HAS UNLIMITED RANGE
*/

void	execute_lld(t_vm *vm, t_process *process)
{
	int a;
	int	b;

	if (!(load_lld(vm, process)))
	{
		move_process(vm, process, skip_invalid_arg(process->arg));
		return ;
	}
	if (process->arg.type[0] == IND_CODE)
		a = read_from_mem(vm, convert_pos_long(process,
					process->arg.param[0]));
	else
		a = process->arg.param[0];
	b = process->arg.param[1];
	if (verbose_level(vm, DEBUG_PRINT_EXEC))
		ft_printf("P %4d | lld %d r%d\n", process->id,
				convert_pos_long_print(process, process->arg.param[0]), b);
	load_in_reg(process, process->arg.param[1], a);
	move_process(vm, process, process->arg.size);
	process->carry = a == 0;
	process->cycle = -1;
}
