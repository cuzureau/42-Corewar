/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memprnt.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/13 11:47:43 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:22:04 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_memprnt() function prints the memory pointed by *addr. In a first
**	time, the hexdecimal representation of each value is displayed, then, the
**	ASCII reprensentation. Each row writen representes 16 bytes in the memory.
**	For example:
**		int main() {
**			char tab[26] = "abcdefghijklmnopqrstuvwxyz";
**			ft_memprnt(tab, sizeof(tab));
**			return(0);
**		}
**		A programm using ft_memprnt like that displays:
**			6162 6364 6566 6768 696a 6b6c 6d6e 6f70 abcdefghip
**			7172 7374 7576 7778 797a                qrstuvwxyz
*/

static void		dsp_hex(unsigned char *ptr, unsigned int size, unsigned int i)
{
	unsigned int	j;
	char			*str;

	j = 0;
	str = STR_BASE_LO;
	while ((j < 16) && ((i + j) < size))
	{
		ft_putchar(str[(*(ptr + i + j) / 16) % 16]);
		ft_putchar(str[*(ptr + i + j) % 16]);
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
	while (j < 16)
	{
		ft_putchar(' ');
		ft_putchar(' ');
		if (j % 2)
			ft_putchar(' ');
		j++;
	}
}

void			ft_memprnt(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*ptr;

	i = 0;
	ptr = (unsigned char *)addr;
	while (i < size)
	{
		dsp_hex(ptr, size, i);
		j = 0;
		while ((j < 16) && ((i + j) < size))
		{
			if (*(ptr + i + j) >= 32 && *(ptr + i + j) <= 126)
				ft_putchar((char)*(ptr + i + j));
			else
				ft_putchar('.');
			j++;
		}
		ft_putchar('\n');
		i += 16;
	}
}
