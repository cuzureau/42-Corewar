/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:01:19 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:08:51 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_lstmap() function applies the f function on every links of the
**	linked list pointed by lst and creates a new list that is the result of
**	those applications.
**
** RETURN VALUES
**	- ft_lstmap() returns a pointer to the head of the new linked list. If one
**	of the malloc fails during the process, a NULL pointer is returned.
**
** NOTE
**	- See libft_typedefs.h to see the t_list structure.
*/

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list			*fresh;
	t_list			*tmp;

	if (!lst || !f)
		return (NULL);
	tmp = f(lst);
	fresh = tmp;
	if (!lst || !tmp)
		return (NULL);
	while (lst->next)
	{
		lst = lst->next;
		tmp->next = f(lst);
		tmp = tmp->next;
	}
	return (fresh);
}
