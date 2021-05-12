/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/12 15:45:52 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	int		read_return;

	read_return = read(fd, buf, BUFFER_SIZE);
	buf[read_return] = '\0';
	*line = buf;
	return (read_return);
	//return = 1 : une ligne a ete lue
	//return = 0 : La lecture est terminee
	//return = -1 : une erreur est survenue
}
