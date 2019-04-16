/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:44:35 by jayache           #+#    #+#             */
/*   Updated: 2019/03/09 15:39:39 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int	usage(void)
{
	ft_printf("Usage: ./corewar [-dump N | -v |"
			" -n N | -d N] <champion1.cor> <...>\n");
	ft_printf("-dump N : Dumps memory after N cycles then exits\n");
	ft_printf("-v : Show visu\n");
	ft_printf("-d N: debug mode\n");
	ft_printf("-n N <champion.cor>: change the order of the champion\n");
	ft_printf("0 < N < 2147483648\n");
	ft_free();
	return (-1);
}

static void	verify_macros(void)
{
	if (MAX_PLAYERS * CHAMP_MAX_SIZE >= MEM_SIZE)
		error("Invalid macro: MEM_SIZE is too small.\n", 0, 0, 0);
	if (REG_NUMBER <= 0)
		error("Invalid macro: REG_NUMBER is too small.\n", 0, 0, 0);
}

int			main(int ac, char **av)
{
	t_vm *vm;

	if (ac < 2)
		error("Missing parameter !\n", 0, 0, 0);
	verify_macros();
	vm = init_vm();
	if (parse(ac, av, NULL, vm) == -1)
		return (usage());
	init_processes(vm);
	if (load_players(vm) == -1)
	{
		ft_free();
		return (-1);
	}
	game_loop(vm);
	if (vm->dump != -1 && vm->dump <= vm->cycle && !vm->visu)
		print_memory(vm->arena, -1);
	else if (!vm->visu)
		print_winner(vm);
	ft_free();
	return (0);
}
