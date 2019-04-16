/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/13 16:53:50 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:11:40 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_strclr() function sets every characters of the string s to zero.
*/

void			ft_strclr(char *s)
{
	if (s)
		ft_bzero(s, ft_strlen(s));
}
