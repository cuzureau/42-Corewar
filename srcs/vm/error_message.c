/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/08 00:00:03 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 16:05:26 by jayache          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

int		error_message(char const *str, void *a, void *b, void *c)
{
	ft_printf(str, a, b, c);
	return (-1);
}

void	error(char const *str, void *a, void *b, void *c)
{
	error_message(str, a, b, c);
	ft_free();
	exit(0);
}
