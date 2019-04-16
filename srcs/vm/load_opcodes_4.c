/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_opcodes_4.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 14:53:27 by jayache           #+#    #+#             */
/*   Updated: 2019/03/04 14:54:06 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** LOADS LLD AND RETURNS 0 IF IT ISN'T VALID
** LD MUST HAVE TWO ARGS, A VALUE (IND/DIR) AND A REGISTER
*/

int	load_lld(t_vm *vm, t_process *process)
{
	process->arg = read_arg(vm->arena, process->pc, 4);
	if (valid_arg_nb(process->arg) != 2)
		return (0);
	if ((process->arg.type[0] == DIR_CODE || process->arg.type[0] == IND_CODE)
			&& process->arg.type[1] == REG_CODE)
		return (1);
	return (0);
}
