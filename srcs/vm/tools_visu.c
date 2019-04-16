/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_visu.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:29:17 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/10 12:05:02 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		init_visu(void)
{
	curs_set(0);
	nodelay(stdscr, TRUE);
	start_color();
	init_color(COLOR_BACK, 209, 204, 192);
	init_color(COLOR_BACK2, 246, 185, 59);
	init_color(COLOR_BACK3, 206, 206, 206);
	init_color(COLOR_TXT1, 235, 47, 6);
	init_color(COLOR_TXT2, 164, 231, 223);
	init_color(COLOR_TXT3, 145, 40, 59);
	init_color(COLOR_NULL, 255, 255, 255);
	init_pair(0, COLOR_BACK, COLOR_BACK);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_NULL, COLOR_BLACK);
	init_pair(7, COLOR_RED, COLOR_GREEN);
	init_pair(8, COLOR_NULL, COLOR_GREEN);
	init_pair(9, COLOR_NULL, COLOR_RED);
	init_pair(10, COLOR_NULL, COLOR_YELLOW);
	init_pair(11, COLOR_NULL, COLOR_BLUE);
	init_pair(12, COLOR_WHITE, COLOR_NULL);
}

int			check_id(t_vm *vm, int i)
{
	t_player *player;

	player = vm->player;
	while (player)
	{
		if (player->nb == i)
			return (player->color);
		player = player->next;
	}
	return (0);
}

void		back(WINDOW *wnd, int x, int y)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	wmove(wnd, 0, 0);
	move(0, 0);
	while (i < y)
	{
		while (j < x)
		{
			wprintw(wnd, " ");
			j++;
		}
		j = 0;
		wmove(wnd, i, j);
		i++;
	}
}

void		back_room(void)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	move(0, 0);
	while (j < LINES)
	{
		while (i < COLS)
		{
			printw(" ");
			i++;
		}
		i = 0;
		j++;
	}
}

void		free_wnd(WINDOW *arena, WINDOW *box, WINDOW *info, WINDOW *player)
{
	delwin(arena);
	delwin(box);
	delwin(info);
	delwin(player);
}
