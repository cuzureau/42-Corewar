/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fork_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:24:27 by jayache           #+#    #+#             */
/*   Updated: 2019/03/10 17:31:00 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** RETURN A CLONED PROCESS
*/

t_process	*clone(t_vm *vm, t_process *p)
{
	t_process	*f;
	int			i;

	i = 0;
	if (!(f = ft_gmemalloc(sizeof(t_process)))
			|| !(f->regist = ft_gmemalloc(sizeof(int) * (REG_NUMBER + 1))))
		error("Malloc failed !\n", 0, 0, 0);
	while (i < REG_NUMBER)
	{
		f->regist[i] = p->regist[i];
		++i;
	}
	f->carry = p->carry;
	f->cycle = -1;
	f->pc = p->pc;
	f->alive = p->alive;
	f->lives = p->lives;
	f->id = ((t_process*)vm->processes->content)->id + 1;
	return (f);
}

/*
** APPEND A PROCES TO THE VM
*/

void		add_process(t_vm *vm, t_process *f)
{
	t_list *l;

	if (!(l = ft_gmemalloc(sizeof(t_list))))
		error("Malloc failed !\n", 0, 0, 0);
	l->content = f;
	l->next = vm->processes;
	vm->processes = l;
}
