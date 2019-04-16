/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/12 04:44:02 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/07 11:56:27 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	chose_color(t_vm *vm, WINDOW *war, int i)
{
	int nb;

	nb = 0;
	if (vm->info_arena[i] != 0)
	{
		nb = check_id(vm, vm->info_arena[i]);
		if (nb == 1)
			wattron(war, COLOR_PAIR(2));
		else if (nb == 2)
			wattron(war, COLOR_PAIR(3));
		else if (nb == 3)
			wattron(war, COLOR_PAIR(4));
		else if (nb == 4)
			wattron(war, COLOR_PAIR(5));
	}
	else
		wattron(war, COLOR_PAIR(6));
}

static void	check_and_chose_cursor(t_vm *vm, WINDOW *war, t_process *process)
{
	int		nb;

	nb = 0;
	process->pc %= MEM_SIZE;
	nb = check_id(vm, process->player_id);
	if (nb == 1)
		wattron(war, COLOR_PAIR(8));
	else if (nb == 2)
		wattron(war, COLOR_PAIR(9));
	else if (nb == 3)
		wattron(war, COLOR_PAIR(10));
	else if (nb == 4)
		wattron(war, COLOR_PAIR(11));
	else
		wattron(war, COLOR_PAIR(12));
}

static void	print_cursor(t_vm *vm, WINDOW *war)
{
	t_list		*lst;
	t_process	*process;
	int			lines;
	int			cols;

	lst = vm->processes;
	wmove(war, 0, 0);
	vm->nb_process = 0;
	while (lst)
	{
		vm->nb_process += 1;
		process = (t_process*)lst->content;
		lines = process->pc / 64;
		cols = (process->pc % 64) * 3;
		wmove(war, lines, cols);
		check_and_chose_cursor(vm, war, process);
		wprintw(war, "%.2x ", (unsigned char)vm->arena[process->pc]);
		lst = lst->next;
	}
}

static int	print_arena(t_vm *vm, WINDOW *war)
{
	char	*arena;
	int		i;
	int		line;

	i = 0;
	line = 1;
	arena = vm->arena;
	wattron(war, COLOR_PAIR(2));
	wmove(war, 0, 0);
	while (i < MEM_SIZE)
	{
		if (i % 64 == 0 && i != 0)
			wmove(war, line++, 0);
		chose_color(vm, war, i);
		wprintw(war, "%.2x ", (unsigned char)arena[i++]);
	}
	print_cursor(vm, war);
	return (0);
}

int			war_page(t_vm *vm, int end)
{
	WINDOW	*arena;
	WINDOW	*box;
	WINDOW	*info;
	WINDOW	*player;

	back_room();
	arena = subwin(stdscr, 64, 192, LINES / 5, 1);
	back(arena, 192, 64);
	box = subwin(stdscr, 7, 44, 5, COLS / 4.5);
	back(box, 44, 7);
	info = subwin(stdscr, 25, 40, LINES / 5, COLS / 1.85);
	back(info, 40, 25);
	player = subwin(stdscr, 39, 40, LINES / 2, COLS / 1.85);
	back(player, 40, 39);
	print_war_title(box);
	print_info(vm, info, end);
	print_player(vm, player);
	print_arena(vm, arena);
	wrefresh(box);
	wrefresh(info);
	wrefresh(player);
	wrefresh(arena);
	refresh();
	free_wnd(arena, box, info, player);
	return (0);
}
