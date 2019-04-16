/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg_by_size.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 14:30:35 by jayache           #+#    #+#             */
/*   Updated: 2019/03/01 15:23:34 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

/*
** READS A SIZE ONE ARG
** EX: REGISTERS
*/

char	arg_size_1(char *arena, int pos)
{
	return (arena[pos % MEM_SIZE]);
}

/*
** READS A SIZE TWO ARG
** EX: INDIRECTS AND DIRECTS
*/

short	arg_size_2(char *arena, int pos)
{
	unsigned short	val;
	unsigned char	*a;

	a = (unsigned char*)arena;
	val = a[pos % MEM_SIZE];
	val = (unsigned short)((val << 8) + a[(pos + 1) % MEM_SIZE]);
	return ((short)val);
}

/*
** READS A SIZE FOUR ARG
** EX: DIRECTS AND LIVE
*/

int		arg_size_4(char *arena, int pos)
{
	unsigned int	val;
	unsigned char	*a;

	a = (unsigned char*)arena;
	val = a[pos % MEM_SIZE];
	val = (val << 8) + a[(pos + 1) % MEM_SIZE];
	val = (val << 8) + a[(pos + 2) % MEM_SIZE];
	val = (val << 8) + a[(pos + 3) % MEM_SIZE];
	return ((int)val);
}
