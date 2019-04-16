/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xmazella <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 22:03:03 by xmazella          #+#    #+#             */
/*   Updated: 2019/03/08 17:26:46 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static int		add_to_list(t_vm *vm, char *name, int nb, int tmp)
{
	t_player	*player;

	++vm->nb_players;
	if (!(player = (t_player *)ft_malloc(sizeof(*player))))
		error(ERROR_MALLOC1, 0, 0, 0);
	if (!(player->name = ft_gstrdup(name)))
		error(ERROR_MALLOC2, 0, 0, 0);
	if (tmp == -1 && check_nb_player(nb, vm) == -1)
		error("ERROR: identhic numbers\n", 0, 0, 0);
	player->nb = nb;
	player->nb_tmp = tmp;
	player->lives = 0;
	if (!vm->player)
	{
		vm->player = player;
		player->next = NULL;
		return (0);
	}
	player->next = vm->player;
	vm->player = player;
	return (0);
}

static int		check_opt_number_player(char **av, int i)
{
	char	*ptr;

	ptr = NULL;
	if (ft_strcmp(av[i], "-n"))
		return (error_message("Error: %s is not a valid flag\n", av[i], 0, 0));
	if (!(av[i + 1] && ft_str_isdigit(av[i + 1])
		&& (ft_strlen(av[i + 1]) < 11)))
		return (error_message(ERROR_FLAGN1, 0, 0, 0));
	if (!(av[i + 2] && (ptr = ft_strrchr(av[i + 2], '.'))
		&& ft_strlen(ptr) == 4 && ft_strnequ(ptr, ".cor", 4)))
		return (error_message(ERROR_CHAMPION, 0, 0, 0));
	return (0);
}

static int		check_valid_number(char **av, int i, int swap, t_vm *vm)
{
	long long		tmp;

	tmp = ft_atoll(av[i + 1]);
	if (tmp <= 0 || tmp > 2147483647)
	{
		if (swap == 1)
			return (error_message(ERROR_DEBUG2, 0, 0, 0));
		else if (swap == 2)
			return (error_message(ERROR_FLAGD2, 0, 0, 0));
		else
			return (error_message(ERROR_FLAGN2, 0, 0, 0));
	}
	if (swap == 1)
		vm->debug = tmp;
	else if (swap == 2)
		vm->dump = tmp;
	else
		add_to_list(vm, av[i + 2], ft_atoi(av[i + 1]), -1);
	return ((swap == 3) ? 2 : 1);
}

static int		parse_opt(char **av, int i, t_vm *vm)
{
	if (!ft_strcmp(av[i], "-v") && (vm->visu = 1))
		return (0);
	if (!ft_strcmp(av[i], "-d"))
	{
		if (av[i + 1] && ft_str_isdigit(av[i + 1]) && ft_strlen(av[i + 1]) < 11)
			return (check_valid_number(av, i, 1, vm));
		else if (!av[i + 1] || (av[i + 1] && !ft_str_isdigit(av[i + 1])))
			return (error_message(ERROR_DEBUG1, 0, 0, 0));
		else
			return (error_message(ERROR_DEBUG2, 0, 0, 0));
	}
	else if (!ft_strcmp(av[i], "-dump"))
	{
		if (av[i + 1] && ft_str_isdigit(av[i + 1]) && ft_strlen(av[i + 1]) < 11)
			return (check_valid_number(av, i, 2, vm));
		else if (!av[i + 1] || (av[i + 1] && !ft_str_isdigit(av[i + 1])))
			return (error_message(ERROR_FLAGD1, 0, 0, 0));
		else
			return (error_message(ERROR_FLAGD2, 0, 0, 0));
	}
	else if (check_opt_number_player(av, i) != -1)
		return (check_valid_number(av, i, 3, vm));
	return (-1);
}

int				parse(int ac, char **av, char *ptr, t_vm *vm)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (++i <= ac && av[i])
	{
		if (av[i][0] == '-')
		{
			if ((vm->jump = parse_opt(av, i, vm)) != -1)
				i += vm->jump;
			else
				return (-1);
		}
		else if ((ptr = ft_strrchr(av[i], '.')))
		{
			if ((ft_strlen(ptr) == 4 && ft_strnequ(ptr, ".cor", 4)))
				add_to_list(vm, av[i], 0, ++j);
			else
				return (-1);
		}
		else if (av[i][0] != '-')
			return (error_message("Error: %s unvalid argument\n", av[i], 0, 0));
	}
	return (checkplayer_and_sort(vm));
}
