/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   players_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 16:41:19 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 15:07:07 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

t_header	*get_header(t_vm *vm, int nb)
{
	t_player	*players;
	int			i;

	players = vm->player;
	i = 0;
	while (i < nb && players)
	{
		players = players->next;
		++i;
	}
	if (players)
		return (&players->header);
	return (0);
}

char		*get_player_name(t_vm *vm, int id)
{
	t_player	*players;
	int			i;

	players = vm->player;
	i = 0;
	while (players)
	{
		if (players->nb == id)
			return (players->header.prog_name);
		players = players->next;
		++i;
	}
	error("Invalid players ?\n", 0, 0, 0);
	return (0);
}

int			get_player_number(t_vm *vm, int nb)
{
	t_player	*players;
	int			i;

	players = vm->player;
	i = 0;
	while (i < nb && players)
	{
		players = players->next;
		++i;
	}
	if (players)
		return (players->nb);
	error("Player doesn't exist\n", 0, 0, 0);
	return (0);
}

t_player	*get_player_struct(t_vm *vm, int nb)
{
	t_player	*players;
	int			i;

	players = vm->player;
	i = 0;
	while (i < nb && players)
	{
		players = players->next;
		++i;
	}
	if (players)
		return (players);
	error("Player doens't exist\n", 0, 0, 0);
	return (0);
}
