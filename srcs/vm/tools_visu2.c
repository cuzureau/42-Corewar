/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_visu2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/10 12:14:58 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/10 16:54:50 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

void		chose_color_playerinfo(t_vm *vm, WINDOW *info, int id)
{
	int			nb;
	t_player	*player;

	nb = 0;
	player = vm->player;
	while (player)
	{
		if (player->color == id)
			nb = player->color;
		player = player->next;
	}
	if (nb == 1)
		wattron(info, COLOR_PAIR(2));
	else if (nb == 2)
		wattron(info, COLOR_PAIR(3));
	else if (nb == 3)
		wattron(info, COLOR_PAIR(4));
	else if (nb == 4)
		wattron(info, COLOR_PAIR(5));
	else
		wattron(info, COLOR_PAIR(1));
}
