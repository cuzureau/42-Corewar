/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room_visu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/27 14:23:33 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/05 17:18:38 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void		print_room_title(void)
{
	move(LINES / 2, COLS / 2 - 35);
	printw(" ######   #######  ########  #####"\
			"### ##      ##   ###    ########");
	move(LINES / 2 + 1, COLS / 2 - 35);
	printw("##    ## ##     ## ##     ## ##     "\
			"  ##  ##  ##   ## ##   ##     ##");
	move(LINES / 2 + 2, COLS / 2 - 35);
	printw("##       ##     ## ##     ## ##      "\
			" ##  ##  ##  ##   ##  ##     ##");
	move(LINES / 2 + 3, COLS / 2 - 35);
	printw("##       ##     ## ########  ######  "\
			" ##  ##  ## ##     ## ########");
	move(LINES / 2 + 4, COLS / 2 - 35);
	printw("##       ##     ## ##   ##   ##       "\
			"##  ##  ## ######### ##   ## ");
	move(LINES / 2 + 5, COLS / 2 - 35);
	printw("##    ## ##     ## ##    ##  ##      "\
			" ##  ##  ## ##     ## ##    ##");
	move(LINES / 2 + 6, COLS / 2 - 35);
	printw(" ######   #######  ##     ## ######## "\
			" ###  ###  ##     ## ##     ##");
}

static void		print_room_space(int i)
{
	move(LINES / 1.5, COLS / 2 - 6);
	if (i % 2)
		printw("press space");
	else
		printw("           ");
	move(LINES / 10, COLS / 2 - 17);
}

int				room_page(void)
{
	int		i;
	t_win	*box;

	i = 0;
	init_visu();
	attron(COLOR_PAIR(1));
	box = subwin(stdscr, LINES, COLS, 0, 0);
	back_room();
	box(box, ACS_VLINE, ACS_HLINE);
	wrefresh(box);
	delwin(box);
	print_room_title();
	while (++i)
	{
		if (getch() == 32)
			break ;
		print_room_space(i);
		printw("XMAZELLA LBRANGIE JAYACHE CUZUREAU");
		refresh();
		usleep(100000);
	}
	return (0);
}
