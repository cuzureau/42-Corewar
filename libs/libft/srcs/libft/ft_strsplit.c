/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/15 16:45:34 by lbrangie          #+#    #+#             */
/*   Updated: 2019/03/09 14:31:33 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strsplit() function allocates an null-terminated array of
**	null-terminated strings representing the spliting of the string s on every
**	characters c whitin it.
**
** RETURN VALUES
**	- ft_strsplit() returns a pointer to the allocated array, or NULL if an
**	error occured.
*/

static size_t	ft_cntwrd(const char *s, char c)
{
	unsigned int	i;
	size_t			nb_wrd;
	unsigned char	lever;

	i = 0;
	nb_wrd = 0;
	lever = 1;
	while (s[++i])
	{
		if (ft_isascii(s[i]) && s[i] != c)
		{
			if (lever)
				nb_wrd++;
			lever = 0;
		}
		if (s[i] == c)
			lever = 1;
	}
	return (nb_wrd);
}

static size_t	ft_strclen(const char *s, char c)
{
	int				size;

	size = 0;
	while (*s != c && *s)
	{
		size++;
		s++;
	}
	return (size);
}

char			**ft_strsplit(const char *s, char c)
{
	char			**tab;
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	if (!s || !(tab = (char**)malloc(sizeof(tab) * (ft_cntwrd(s, c) + 2))))
		return (NULL);
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{
			if (!(tab[j++] = ft_strsub(s, i, ft_strclen(&s[i], c))))
				return (NULL);
			i = i + ft_strclen(&s[i], c);
		}
	}
	tab[j] = NULL;
	return (tab);
}
