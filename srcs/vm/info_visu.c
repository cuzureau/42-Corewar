/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:44:35 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/10 12:18:05 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		print_war_title(WINDOW *box)
{
	wmove(box, 0, 0);
	wprintw(box, "   ______              _       __          ");
	wmove(box, 1, 0);
	wprintw(box, "  / ____/___  ________| |     / /___ ______");
	wmove(box, 2, 0);
	wprintw(box, " / /   / __ \\/ ___/ _ \\ | /| / / __ `/ ___/");
	wmove(box, 3, 0);
	wprintw(box, "/ /___/ /_/ / /  /  __/ |/ |/ / /_/ / /    ");
	wmove(box, 4, 0);
	wprintw(box, "\\____/\\____/_/   \\___/|__/|__/\\__,_/_/  ");
}

int			search_and_print_winner(t_vm *vm, WINDOW *info)
{
	t_player *player;

	player = vm->player;
	while (player)
	{
		if (vm->last_live_id == player->nb)
		{
			wprintw(info, "WINNER <%s>", player->header.prog_name);
			return (1);
		}
		player = player->next;
	}
	wprintw(info, "NO WINNER => EQUALITY");
	return (0);
}

void		print_info(t_vm *vm, WINDOW *info, int end)
{
	wmove(info, 0, 18);
	wprintw(info, "INFO");
	wmove(info, 2, 0);
	wprintw(info, "CYCLE			%d", vm->cycle);
	wmove(info, 4, 0);
	wprintw(info, "CYCLE TO DIE		%d", CYCLE_TO_DIE - vm->delta);
	wmove(info, 6, 0);
	wprintw(info, "CYCLE DELTA		%d", vm->delta);
	wmove(info, 8, 0);
	wprintw(info, "PROCESSES		%d", vm->nb_process);
	wmove(info, 10, 0);
	wprintw(info, "NUMBERS PLAYERS		%d", vm->nb_players);
	wmove(info, 12, 0);
	wprintw(info, "NUMBERS CHECKS		%d", vm->nb_checks);
	wmove(info, 14, 0);
	wprintw(info, "NUMBERS LIVES		%d", vm->nb_lives);
	wmove(info, 16, 0);
	if (end)
		search_and_print_winner(vm, info);
}

void		domination_arena(int *info_arena, t_player *player)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < MEM_SIZE)
	{
		if (info_arena[i] == player->nb)
			nb++;
		i++;
	}
	player->div_arena = (nb * 100) / MEM_SIZE;
	player->mod_arena = (nb * 100) % MEM_SIZE;
}

void		print_player(t_vm *vm, WINDOW *players)
{
	t_player		*player;
	unsigned int	i;
	int				nb;

	i = -1;
	nb = -1;
	player = vm->player;
	while (++i < vm->nb_players)
	{
		chose_color_playerinfo(vm, players, player->color);
		wmove(players, ++nb, 17);
		wprintw(players, "PLAYER %d", player->nb);
		wmove(players, ++nb, 0);
		wprintw(players, "NAME %s", player->header.prog_name);
		wmove(players, ++nb, 0);
		wprintw(players, "NUMBERS LIVES %d", player->lives);
		wmove(players, ++nb, 0);
		domination_arena(vm->info_arena, player);
		wprintw(players, "SCORE PLAYER %d,%d%%", player->div_arena,
				player->mod_arena);
		wmove(players, ++nb, 0);
		player = player->next;
	}
}
