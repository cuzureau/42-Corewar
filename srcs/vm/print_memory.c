/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_memory.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/03 15:07:33 by jayache           #+#    #+#             */
/*   Updated: 2019/03/06 15:24:31 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void	p_arg(char const *name, int id, t_arg arg)
{
	int	i;

	i = 0;
	ft_printf("P %4d | %s", id, name);
	while (arg.type[i] && i < 3)
	{
		if (arg.type[i] == PARAM_REGISTER)
			ft_printf(" r%d", arg.param[i]);
		else
			ft_printf(" %d", arg.param[i]);
		++i;
	}
	ft_printf("\n");
}

void	print_mem_chunk(t_vm *vm, int start, int l)
{
	int	i;

	i = 0;
	while (i < l)
	{
		ft_printf("%.2x", (unsigned char)vm->arena[(start + i) % MEM_SIZE]);
		if (i < l - 1)
			ft_printf(" ");
		++i;
	}
}

void	print_memory(char *arena, int pos)
{
	int	i;

	i = 0;
	ft_printf("0x0000 : ");
	while (i < MEM_SIZE)
	{
		if (i % 32 == 0 && i != 0)
			ft_printf("\n%#.4x : ", i);
		if (i == pos)
			ft_printf("%@%.2x%@ ", RED, (unsigned char)arena[i], EOC);
		else
			ft_printf("%.2x ", (unsigned char)arena[i]);
		++i;
	}
	ft_printf("\n");
}
