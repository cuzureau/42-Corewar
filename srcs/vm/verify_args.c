/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 20:48:36 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 15:12:11 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** SHORT WAY OF TRYING MULTIPLE POSSIBLE VALUES
*/

int			arg_is(int arg, int a, int b)
{
	if (b == 0)
		return (arg == a);
	return (arg == a || arg == b);
}

/*
** CALC THE NUMBER OF BYTES TO JUMP
** CURRENTLY JUST ARG.SIZE BECAUSE IT MAKES SENSE
*/

int			skip_invalid_arg(t_arg arg)
{
	return (arg.size);
}

/*
** CALC THE NUMBER OF VALID ARGS
*/

int			valid_arg_nb(t_arg arg)
{
	int	cnt;

	cnt = 0;
	while (cnt < 3 && arg.type[cnt])
	{
		if (arg.type[cnt] == REG_CODE)
		{
			if (arg.param[cnt] > REG_NUMBER || arg.param[cnt] <= 0)
				return (0);
		}
		if (arg.type[cnt] != REG_CODE && arg.type[cnt]
				!= IND_CODE && arg.type[cnt] != DIR_CODE)
			return (0);
		cnt++;
	}
	return (cnt);
}
