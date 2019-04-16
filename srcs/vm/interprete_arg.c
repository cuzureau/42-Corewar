/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   interprete_arg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/09 18:20:33 by jayache           #+#    #+#             */
/*   Updated: 2019/03/03 15:47:05 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		get_arg_value(t_process *p, t_arg arg, int nb)
{
	if (nb > 2)
		error("Error in interprete_arg: nb too big!\n", 0, 0, 0);
	if (arg.type[nb] == PARAM_REGISTER)
		return (read_from_reg(p, arg.param[nb]));
	else if (arg.type[nb] == PARAM_INDIRECT)
		return (arg.param[nb]);
	else if (arg.type[nb] == PARAM_DIRECT)
		return (arg.param[nb]);
	return (0);
}
