/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iscntrl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/20 10:31:51 by lbrangie          #+#    #+#             */
/*   Updated: 2018/11/13 11:20:49 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_iscntrl() function tests if the integer c is a control character.
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
**	- ft_iscntrl() returns 1 if the test is true or 0 if the test is false.
*/

int				ft_iscntrl(int c)
{
	return ((c >= 0 && c <= 31) || c == 127);
}
