/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_arg_by_code.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 17:47:03 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 15:12:47 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	read_first_arg(t_arg *arg, int pos, char *arena, int size)
{
	int code;

	code = (arg->codage & FIRST_PARAM_MASK) >> 6;
	if (code == PARAM_REGISTER)
	{
		arg->size += 1;
		arg->param[0] = arg_size_1(arena, pos);
	}
	else if (code == IND_CODE || (code == DIR_CODE && size == 2))
	{
		arg->size += 2;
		arg->param[0] = arg_size_2(arena, pos);
	}
	else if ((code == PARAM_DIRECT) && size == 4)
	{
		arg->size += 4;
		arg->param[0] = arg_size_4(arena, pos);
	}
	arg->type[0] = code;
}

static void	read_second_arg(t_arg *arg, int pos, char *arena, int size)
{
	int code;

	code = (arg->codage & SECOND_PARAM_MASK) >> 4;
	if (code == PARAM_REGISTER)
	{
		arg->size += 1;
		arg->param[1] = arg_size_1(arena, pos);
	}
	else if (code == IND_CODE || (code == DIR_CODE && size == 2))
	{
		arg->param[1] = arg_size_2(arena, pos);
		arg->size += 2;
	}
	else if (code == PARAM_DIRECT && size == 4)
	{
		arg->param[1] = arg_size_4(arena, pos);
		arg->size += 4;
	}
	arg->type[1] = code;
}

static void	read_third_arg(t_arg *arg, int pos, char *arena, int size)
{
	int code;

	code = (arg->codage & THIRD_PARAM_MASK) >> 2;
	if (code == PARAM_REGISTER)
	{
		arg->param[2] = arg_size_1(arena, pos);
		arg->size += 1;
	}
	else if (code == IND_CODE || (code == DIR_CODE && size == 2))
	{
		arg->param[2] = arg_size_2(arena, pos);
		arg->size += 2;
	}
	else if (code == PARAM_DIRECT && size == 4)
	{
		arg->param[2] = arg_size_4(arena, pos);
		arg->size += 4;
	}
	arg->type[2] = code;
}

t_arg		read_arg(char *arena, int pos, int size)
{
	t_arg arg;

	ft_bzero(&arg, sizeof(t_arg));
	arg.opcode = (unsigned char)arena[pos % MEM_SIZE];
	arg.codage = (unsigned char)arena[(pos + 1) % MEM_SIZE];
	read_first_arg(&arg, pos + 2, arena, size);
	read_second_arg(&arg, pos + 2 + arg.size, arena, size);
	read_third_arg(&arg, pos + 2 + arg.size, arena, size);
	arg.size += 2;
	return (arg);
}
