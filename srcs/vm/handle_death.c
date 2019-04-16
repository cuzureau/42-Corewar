/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_death.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:27:30 by jayache           #+#    #+#             */
/*   Updated: 2019/03/07 14:08:12 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** VERIFIES IF THE PROCESS HAS LIVED SINCE LAST CHECK
** ALSO UPDATES THE DELTA IF THE CONDITION ARE MET
*/

static void	die(t_vm *vm, t_process *process)
{
	if (!process->alive)
		return ;
	if (process->lives == 0 || CYCLE_TO_DIE - vm->delta <= 0)
	{
		process->alive = 0;
		if (verbose_level(vm, DEBUG_PRINT_DEATHS))
			ft_printf("Process %d hasn't lived for %d cycles (CTD %d)\n",
					process->id, vm->cycle - process->last_live,
					CYCLE_TO_DIE - vm->delta);
	}
	else
	{
		vm->nb_lives += process->lives;
		process->lives = 0;
	}
}

/*
** UPDATES CYCLE_TO_DIE
*/

static void	update_cycle(t_vm *vm)
{
	vm->nb_checks += 1;
	if (vm->nb_lives >= NBR_LIVE)
	{
		vm->delta += CYCLE_DELTA;
		vm->nb_checks = 0;
		if (verbose_level(vm, DEBUG_PRINT_DEATHS))
			ft_printf("Cycle to die is now %d\n", CYCLE_TO_DIE - vm->delta);
	}
	if (vm->nb_checks >= MAX_CHECKS)
	{
		vm->delta += CYCLE_DELTA;
		if (verbose_level(vm, DEBUG_PRINT_DEATHS))
			ft_printf("Cycle to die is now %d\n", CYCLE_TO_DIE - vm->delta);
		vm->nb_checks = 0;
	}
	vm->last_check = vm->cycle;
}

/*
** APPLY THE 'DIE' FUNCTION TO EACH PROCESS OF THE VM
*/

void		apply_death(t_vm *vm)
{
	t_list	*current;

	current = vm->processes;
	if (vm->cycle - vm->last_check >= CYCLE_TO_DIE - vm->delta)
	{
		vm->nb_lives = 0;
		while (current)
		{
			die(vm, ((t_process*)current->content));
			current = current->next;
		}
		update_cycle(vm);
	}
}

/*
**	RETURN TRUE IF ALL PROCESSES ARE DEAD
*/

int			check_if_all_dead(t_vm *vm)
{
	t_list	*current;
	int		deads;

	deads = 0;
	current = vm->processes;
	while (current)
	{
		deads += ((t_process*)current->content)->alive;
		current = current->next;
	}
	return (!deads);
}
