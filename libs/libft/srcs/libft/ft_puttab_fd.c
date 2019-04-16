/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puttab_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:03:52 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 15:42:27 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_puttab_fd() function attempts to write the content of the table tab
**	to the object referenced by the descriptor fd.
*/

void			ft_puttab_fd(char **tab, int fd)
{
	int				i;

	if (!tab)
		return ;
	i = -1;
	while (tab[++i])
		ft_putstr_endl_fd(tab[i], fd);
}
