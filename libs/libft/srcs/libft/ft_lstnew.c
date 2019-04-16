/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 16:01:17 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:09:12 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_lstnew() function allocates the memory for a structure t_list, then
**	allocates the memory for the field content in this structure, copies the
**	parameter content into this field and sets the content_size field with the
**	value of the corresponding parameter. If content is null, the field is sets
**	to NULL and the content_size field is sets to 0.
**
** RETURN VALUES
**	- ft_lstnew() returns a pointer to the new structure t_list. If the malloc
**	of the structure or the malloc of the field content in the struture fails,
**	a NULL pointer is returned.
**
** NOTE
**	- See libft_typedefs.h to see the t_list structure.
*/

t_list			*ft_lstnew(const void *content, size_t content_size)
{
	t_list			*fresh;

	if (!(fresh = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		fresh->content = NULL;
		fresh->content_size = 0;
		fresh->next = NULL;
		return (fresh);
	}
	if (!(fresh->content = ft_memalloc(content_size)))
		return (NULL);
	ft_memcpy(fresh->content, content, content_size);
	fresh->content_size = content_size;
	fresh->next = NULL;
	return (fresh);
}
