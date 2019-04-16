/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 15:38:06 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:18:12 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_puttab() function attempts to write the content of the table tab on
**	the standard output, a.k.a. sdtout.
*/

void			ft_puttab(char **tab)
{
	int				i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		ft_putstr_endl(tab[i]);
}
