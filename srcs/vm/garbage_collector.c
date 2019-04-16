/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   garbage_collector.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jayache <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/05 14:26:38 by jayache           #+#    #+#             */
/*   Updated: 2019/03/05 17:38:13 by xmazella         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vm.h"

static void	*allocator(size_t size, int free)
{
	static t_list	*mem;
	t_list			*current;

	if (free)
		return (mem);
	if (!mem)
	{
		if (!(current = (t_list*)malloc(size + sizeof(t_list))))
			error(ERROR_MALLOC1, 0, 0, 0);
	}
	else
	{
		if (!(current = (t_list*)malloc(size + sizeof(t_list))))
			error(ERROR_MALLOC1, 0, 0, 0);
	}
	current->next = mem;
	current->content = &((char*)(current))[sizeof(t_list)];
	mem = current;
	return (current->content);
}

void		*ft_malloc(size_t size)
{
	return (allocator(size, 0));
}

void		ft_free(void)
{
	t_list *to_free;
	t_list *next;

	to_free = allocator(0, 1);
	while (to_free)
	{
		next = to_free->next;
		free(to_free);
		to_free = next;
	}
}

void		*ft_gmemalloc(size_t size)
{
	void *ptr;

	ptr = ft_malloc(size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, size);
	return (ptr);
}

char		*ft_gstrdup(const char *s1)
{
	char	*s2;
	int		x;

	x = 0;
	s2 = ft_malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s2)
	{
		return (NULL);
	}
	while (s1[x])
	{
		s2[x] = s1[x];
		++x;
	}
	s2[x] = '\0';
	return (s2);
}
