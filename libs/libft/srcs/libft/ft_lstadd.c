/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 15:00:03 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:07:11 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_lstadd() function adds the pointer new at the head of a linked
**	list. The pointer *alst is the head of the list. That means that ft_lstadd()
**	will take new and add *alst after. The pointer new will be the new head of
**	the list.
**
** NOTE
**	- See libft_typedefs.h to see the t_list structure.
*/

void			ft_lstadd(t_list **alst, t_list *new)
{
	if (!alst || !new)
		return ;
	new->next = *alst;
	*alst = new;
}
