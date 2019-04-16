/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_iscntrl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/28 13:35:13 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:18:40 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_str_iscntrl() function tests if the string str is full of
**	control characters.
**	This includes the following characters (preceded by their decimal values):
**		  0 'NUL'	  1 'SOH'	  2 'STX'	  3 'ETX'	  4 'EOT'
**		  5 'ENQ'	  6 'ACK'	  7 'BEL'	  8 'BS'	  9 'HT'
**		 10 'NL'	 11 'VT'	 12 'NP'	 13 'CR'	 14 'SO'
**		 15 'SI'	 16 'DLE'	 17 'DC1'	 18 'DC2'	 19 'DC3'
**		 20 'DC4'	 21 'NAK'	 22 'SYN'	 23 'ETB'	 24 'CAN'
**		 25 'EM'	 26 'SUB'	 27 'ESC'	 28 'FS'	 29 'GS'
**		 30 'RS'	 31 'US'	127 'DEL'
**
** RETURN VALUES
**	- ft_str_iscntrl() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_str_iscntrl(char *str)
{
	if (!str)
		return (0);
	while (*str)
		if (!ft_iscntrl(*str++))
			return (0);
	return (1);
}
