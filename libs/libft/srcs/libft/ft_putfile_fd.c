/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putfile_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbrangie <lbrangie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 11:50:21 by lbrangie          #+#    #+#             */
/*   Updated: 2019/02/04 20:16:43 by lbrangie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** DESCRIPTION
**	- The ft_putfile_fd() function attempts to open the file that the name
**	correspond to the string file_name, write that file to the object refenreced
**	by the descriptor fd and close that file.
**
** RETURN VALUES
**	- ft_putfile_fd() returns the number of bytes writen upon successful
**	completion. Otherwise, -1 is returned.
*/

int				ft_putfile_fd(const char *file_name, int fd)
{
	int				fd_file;
	int				len;
	char			*line;

	if ((fd_file = open(file_name, O_RDONLY)) == -1)
		return (ERROR);
	len = 0;
	while (get_next_line(fd_file, &line))
	{
		len += ft_putstr_endl_fd(line, fd);
		ft_strdel(&line);
	}
	ft_strdel(&line);
	if (close(fd_file) == -1)
		return (ERROR);
	return (len);
}
