/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtok.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 14:38:26 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 19:42:07 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strtok() function isolate sequential tokens in a null-terminated
**	string str. These tokens are separated in the string by, at least, one of
**	the characters in charset.
**	The first time ft_strtok() is called, str must be specified; subsequent
**	calls, wishing to obtain further tokens from the same string, should pass a
**	null pointer instead. The separator string charset must be supplied each
**	time but may change between calls.
**
** RETURN VALUES
**	- ft_strtok() returns a pointer to the begenning of the token it found.
**
** EXAMPLE
**	- This code parse the string str, print each token generated and prevent
**	memory leaks.
**
**		char			*str, *tmp, *word;
**		char			*charset = "\\/:;=-";
**
**		str = ft_strdup("This;is.a:test:of=the/string\\tokenizer-function.");
**		tmp = str;
**		while ((word = ft_strtok(str, charset)) && *word && !(str = NULL))
**			printf("%s\n", word);
**		ft_strdel(&tmp);
**		return (0);
*/

char			*ft_strtok(char *str, const char *charset)
{
	static char		*old;

	if (str)
		old = str;
	else if (!old)
		return (NULL);
	str = old + ft_strspn(old, charset);
	old = str + ft_strcspn(str, charset);
	if (old == str)
		return (old = NULL);
	if (*old)
		*old++ = '\0';
	return (str);
}
