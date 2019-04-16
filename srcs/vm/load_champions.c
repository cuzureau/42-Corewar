/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_champions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 21:43:26 by jayache           #+#    #+#             */
/*   Updated: 2019/03/08 17:11:09 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void			load_to_arena(t_vm *vm, char *buffer,
					int len_champ, int pos)
{
	char	*arena;
	int		i;
	int		champ;

	arena = vm->arena;
	champ = vm->len_buffer - len_champ;
	i = 0;
	while (i < len_champ)
	{
		arena[pos] = buffer[champ + i];
		i++;
		pos++;
	}
}

static int			check_header(t_vm *vm, t_header *h)
{
	if (!h->magic || h->magic != COREWAR_EXEC_MAGIC)
		error(ERROR_CHAMPION2, 0, 0, 0);
	if (!h->prog_name[0])
		error(ERROR_CHAMPION3, 0, 0, 0);
	if ((vm->len_buffer - sizeof(*h)) > CHAMP_MAX_SIZE)
		error(ERROR_CHAMPION4, 0, 0, 0);
	if ((unsigned long)vm->len_buffer < sizeof(*h))
		error(ERROR_CHAMPION5, 0, 0, 0);
	if (h->prog_size != vm->len_buffer - sizeof(*h))
		error(ERROR_CHAMPION6, 0, 0, 0);
	return (0);
}

static t_header		load_player(t_vm *vm, int fd, int x)
{
	char		*arena;
	void		*buffer;
	t_header	h;

	arena = vm->arena;
	vm->len_buffer = lseek(fd, 0, SEEK_END);
	lseek(fd, 0, SEEK_SET);
	if (!(buffer = ft_malloc(sizeof(buffer) * vm->len_buffer)))
		error(ERROR_MALLOC1, 0, 0, 0);
	read(fd, buffer, vm->len_buffer);
	h = (*(t_header*)buffer);
	h.magic = byte_reverse(h.magic);
	h.prog_size = byte_reverse(h.prog_size);
	check_header(vm, &h);
	load_to_arena(vm, buffer, h.prog_size, x);
	return (h);
}

void				load_to_info(t_vm *vm, int len, int poss, t_player *player)
{
	while (len > 0)
	{
		vm->info_arena[poss] = player->nb;
		poss++;
		len--;
	}
}

int					load_players(t_vm *vm)
{
	unsigned int			i;
	int						fd;
	int						decal;
	t_player				*player;

	i = 0;
	decal = MEM_SIZE / vm->nb_players;
	vm->info_arena = ft_gmemalloc(sizeof(int) * MEM_SIZE + 1);
	while (i < vm->nb_players)
	{
		if ((player = get_player_struct(vm, vm->nb_players - 1 - i)) == 0)
			error(ERROR_MALLOC1, 0, 0, 0);
		if ((fd = open(player->name, O_RDONLY)) == -1)
			error("Couldn't open player %s\n", player->name, 0, 0);
		player->header = load_player(vm, fd, decal * i);
		load_to_info(vm, player->header.prog_size, decal * i, player);
		close(fd);
		i++;
	}
	return (0);
}
