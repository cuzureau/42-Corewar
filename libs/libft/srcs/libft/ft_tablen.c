/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tablen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/11 16:37:24 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 17:01:10 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_tablen() function computes the length of the array tab.
**
** RETURN VALUES
**	- ft_tablen() returns the number of rows that precedd the terminating NULL
**	pointer.
*/

size_t			ft_tablen(char **tab)
{
	size_t			size;

	size = 0;
	while (tab[size])
		size++;
	return (size);
}
