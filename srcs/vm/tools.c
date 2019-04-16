/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 15:23:55 by jayache           #+#    #+#             */
/*   Updated: 2019/03/04 14:38:40 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** NOTES THE LIVE EVERYWHERE
*/

void	live(t_vm *vm, int player_nb)
{
	t_player *player;

	player = vm->player;
	while (player)
	{
		if (player->nb == -player_nb)
		{
			player->lives += 1;
			vm->last_live_id = player->nb;
			if (verbose_level(vm, DEBUG_PRINT_LIVES))
				ft_printf("Player %d (%s) is said to be alive\n", -player_nb,
						player->header.prog_name);
			return ;
		}
		player = player->next;
	}
}

/*
** PRINTS THE WINNER ONCE THE GAME IS FINISHED
*/

void	print_winner(t_vm *vm)
{
	int		id;
	char	*name;

	id = vm->last_live_id;
	if (id == 0)
		id = get_player_number(vm, 0);
	name = get_player_name(vm, id);
	ft_printf("Contestant %d, \"%s\", has won !\n", id, name);
}
