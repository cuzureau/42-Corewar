/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 15:11:47 by jayache           #+#    #+#             */
/*   Updated: 2019/03/10 17:03:52 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** RETURNS THE VALUE OF A REG
*/

int	read_from_reg(t_process *process, int nb)
{
	if (nb <= 0)
		return (0);
	return (process->regist[(nb - 1) % REG_NUMBER]);
}

/*
** RETURN FOUR BYTES FROM THE MEM, STARTING FROM POS
*/

int	read_from_mem(t_vm *vm, int pos)
{
	unsigned int	val;

	val = (unsigned char)vm->arena[pos % MEM_SIZE];
	val = (val << 8) + (unsigned char)vm->arena[(pos + 1) % MEM_SIZE];
	val = (val << 8) + (unsigned char)vm->arena[(pos + 2) % MEM_SIZE];
	val = (val << 8) + (unsigned char)vm->arena[(pos + 3) % MEM_SIZE];
	return (val);
}

/*
** READS THE VALUE OF THE REG IF IT IS A REG
** RETURNS THE LITERAL VALUE OTHERWISE
*/

int	read_arg_val(t_process *process, int nb)
{
	if (process->arg.type[nb] == PARAM_REGISTER)
		return (read_from_reg(process, process->arg.param[nb]));
	else
		return (process->arg.param[nb]);
}
