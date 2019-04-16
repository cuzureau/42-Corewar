/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strusplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/25 11:52:14 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/05 17:26:25 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strusplit() function allocates an null-terminated array of
**	null-terminated strings representing the spliting of the string s on every
**	characters of the string charset whitin it.
**
** RETURN VALUES
**	- ft_strusplit() returns a pointer to the allocated array, or NULL if an
**	error occured.
*/

static size_t	ft_cntwrd(const char *s, char *charset)
{
	size_t			nb_wrd;

	nb_wrd = 0;
	while (*s)
	{
		s += ft_strcspn(s, charset);
		s += ft_strspn(s, charset);
		if (*s)
			nb_wrd++;
	}
	return (nb_wrd);
}

char			**ft_strusplit(const char *s, char *charset)
{
	char			**tab;
	char			*tmp;
	char			*to_del;
	char			*word;
	size_t			i;

	if (!s || !charset || !(tmp = ft_strdup(s)) || \
		!(tab = (char**)malloc(sizeof(tab) * (ft_cntwrd(s, charset) + 2))))
		return (NULL);
	i = 0;
	to_del = tmp;
	while ((word = ft_strtok(tmp, charset)) && *word && \
		!(tmp = NULL))
		if (!(tab[i++] = ft_strdup(word)))
			return (NULL);
	ft_strdel(&to_del);
	tab[i] = NULL;
	return (tab);
}
