/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:22:21 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/06 17:25:34 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int			parse_player(t_vm *vm)
{
	t_player	*player;
	int			save;

	player = vm->player;
	save = 0;
	while (player)
	{
		if (player->nb_tmp != -1)
		{
			while (check_nb_player(player->nb_tmp + save, vm) == -1)
				save++;
			player->nb = player->nb_tmp + save;
		}
		save = 0;
		player = player->next;
	}
	return (0);
}

static void			sort_nb(t_vm *vm, int i)
{
	int			tmp_int;
	char		*tmp_str;
	t_player	*tmp;

	tmp = vm->player;
	while (tmp->next)
	{
		if ((i == 0 && tmp->nb_tmp < tmp->next->nb_tmp) ||\
				(i == 1 && tmp->nb < tmp->next->nb))
		{
			tmp_int = tmp->nb;
			tmp->nb = tmp->next->nb;
			tmp->next->nb = tmp_int;
			tmp_str = tmp->name;
			tmp->name = tmp->next->name;
			tmp->next->name = tmp_str;
			tmp_int = tmp->nb_tmp;
			tmp->nb_tmp = tmp->next->nb_tmp;
			tmp->next->nb_tmp = tmp_int;
			tmp = vm->player;
		}
		else
			tmp = tmp->next;
	}
}

static void			vm_player_color(t_vm *vm)
{
	t_player	*player;
	int			i;

	player = vm->player;
	i = 1;
	while (player)
	{
		player->color = i++;
		player = player->next;
	}
}

int					checkplayer_and_sort(t_vm *vm)
{
	if (vm->nb_players == 0 || vm->nb_players > MAX_PLAYERS)
		return (error_message("ERROR PLAYER\n", 0, 0, 0));
	sort_nb(vm, 0);
	parse_player(vm);
	sort_nb(vm, 1);
	vm_player_color(vm);
	return (0);
}

int					check_nb_player(int nb, t_vm *vm)
{
	t_player	*player;

	player = vm->player;
	while (player)
	{
		if (player->nb == nb)
			return (-1);
		player = player->next;
	}
	return (0);
}
