/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ptf_buffer.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/09 15:46:52 by lbrangie          #+#    #+#             */
/*   Updated: 2018/06/13 17:09:24 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ptf_buff_add_char(t_buff *buff, const char *format)
{
	if (buff->ret == -1)
		return ;
	if ((buff->index + 1) > PRINTF_BUFF_SIZE)
	{
		buff->ret += write(buff->fd, buff->str, buff->index);
		ptf_buff_flush(buff);
		buff->index = 0;
	}
	buff->str[buff->index++] = *format;
}

void			ptf_buff_add_uchar(t_buff *buff, unsigned char wchar)
{
	if (buff->ret == -1)
		return ;
	if ((buff->index + 1) > PRINTF_BUFF_SIZE)
	{
		buff->ret += write(buff->fd, buff->str, buff->index);
		ptf_buff_flush(buff);
		buff->index = 0;
	}
	buff->str[buff->index++] = wchar;
}

void			ptf_buff_add_str(t_buff *buff, char *add, unsigned int len)
{
	unsigned int	i_add;

	if (buff->ret == -1)
		return ;
	i_add = 0;
	while ((add[i_add]) && (i_add < len))
	{
		if (buff->index < PRINTF_BUFF_SIZE)
			buff->str[buff->index++] = add[i_add++];
		else
		{
			buff->ret += write(buff->fd, buff->str, buff->index);
			ptf_buff_flush(buff);
			buff->index = 0;
		}
	}
}

void			ptf_buff_flush(t_buff *buff)
{
	unsigned int	index;

	index = 0;
	while (index <= PRINTF_BUFF_SIZE)
		buff->str[index++] = '\0';
}

void			ptf_buff_init(t_buff *buff, int fd)
{
	ptf_buff_flush(buff);
	buff->index = 0;
	buff->ret = 0;
	buff->fd = fd;
}
