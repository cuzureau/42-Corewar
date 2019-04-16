/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:58:03 by jayache           #+#    #+#             */
/*   Updated: 2019/03/08 17:26:40 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** EXECUTE A PROCESS CYCLE
*/

static void		execute(t_vm *vm, t_process *process)
{
	process->pc %= MEM_SIZE;
	if (process->cycle > 0)
		process->cycle -= 1;
	if (process->cycle == 0)
	{
		execute_instruction(vm, process);
		load_next_instruction(vm, process);
	}
	else if (process->cycle == -1)
	{
		load_next_instruction(vm, process);
		process->cycle -= 1;
	}
}

/*
** INTRODUCE THE CONTESTANTS WHEN THE VM START
*/

static	void	init_loop(t_vm *vm)
{
	t_header	*h;
	int			nb;
	int			i;

	vm->cycle = 1;
	if (vm->visu)
	{
		initscr();
		return ;
	}
	i = 4;
	if (!vm->visu)
		ft_printf("Introducing contestants...\n");
	while (i >= 0)
	{
		h = get_header(vm, i);
		if (h)
			nb = get_player_number(vm, i);
		i--;
		if (h && !vm->visu)
			ft_printf("* Player %d, weighing %d bytes, \"%s\" (\"%s\") !\n", nb,
					h->prog_size, h->prog_name, h->comment);
	}
}

/*
** POST PROCESSING OF A LOOP
** CHECK FOR DEATHS, DRAW AND UPDATE THE CYCLE NUMBER
** RETURN 1 IF THE FIGHT HAS ENDED
*/

static void		end_loop(t_vm *vm)
{
	war_page(vm, 1);
	while (1)
	{
		move(0, 0);
		if (getch() == 32)
			break ;
	}
}

static int		post_loop(t_vm *vm)
{
	apply_death(vm);
	if (check_if_all_dead(vm))
		return (1);
	if (vm->visu && (vm->nb_players > 4 || MEM_SIZE > 4096))
	{
		clear();
		endwin();
		error(ERROR_VISU, 0, 0, 0);
	}
	if (vm->visu && vm->cycle == 1)
		room_page();
	if (vm->visu)
		war_page(vm, 0);
	vm->cycle += 1;
	return (0);
}

/*
** MAIN LOOP
*/

void			game_loop(t_vm *vm)
{
	t_list		*current;
	t_list		*last;

	init_loop(vm);
	while ((vm->cycle <= vm->dump || vm->dump == -1))
	{
		current = vm->processes;
		if (verbose_level(vm, DEBUG_PRINT_CYCLE))
			ft_printf("It is now cycle %d\n", vm->cycle);
		while (current)
		{
			if (((t_process*)current->content)->alive)
				execute(vm, (t_process*)current->content);
			last = current;
			current = current->next;
		}
		if (post_loop(vm))
			break ;
	}
	if (vm->visu)
	{
		end_loop(vm);
		clear();
		endwin();
	}
}
