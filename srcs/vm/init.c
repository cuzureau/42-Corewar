/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:05:10 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 15:24:04 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
**	INITS A SINGLE PROCESS
*/

static t_process	*init_process(t_vm *vm, int nb, unsigned int id)
{
	t_process *p;

	if (!(p = ft_gmemalloc(sizeof(t_process))))
		error("Could not malloc the process %d!\n", (void*)(uintptr_t)nb, 0, 0);
	if (!(p->regist = ft_gmemalloc(sizeof(int) * (REG_NUMBER + 1))))
		error("Could not malloc the process %d!\n", (void*)(uintptr_t)nb, 0, 0);
	p->id = id + 1;
	p->pc = ((MEM_SIZE / vm->nb_players) * id);
	load_in_reg(p, 1, -nb);
	p->cycle = -1;
	p->alive = 1;
	return (p);
}

/*
** INITS THE VM WITH DEFAULT VALUES
*/

t_vm				*init_vm(void)
{
	t_vm	*vm;

	if (!(vm = ft_gmemalloc(sizeof(t_vm))))
		error("Could not malloc the vm!\n", 0, 0, 0);
	if (!(vm->arena = ft_gmemalloc(MEM_SIZE)))
		error("Could not malloc the arena!\n", 0, 0, 0);
	vm->dump = -1;
	return (vm);
}

/*
** INITS ALL THE PROCESSES
*/

void				init_processes(t_vm *vm)
{
	unsigned int	i;
	t_list			*current;

	if (!(vm->processes = (t_list*)ft_gmemalloc(sizeof(t_list))))
		error("Malloc error!\n", 0, 0, 0);
	current = vm->processes;
	i = 0;
	while (i < vm->nb_players)
	{
		current->content = init_process(vm, get_player_number(vm, i),
				vm->nb_players - i - 1);
		if (i < vm->nb_players - 1)
			if (!(current->next = ft_gmemalloc(sizeof(t_list))))
				error("Malloc error !\n", 0, 0, 0);
		current = current->next;
		++i;
	}
}
