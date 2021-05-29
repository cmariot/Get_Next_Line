/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/29 15:31:07 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	int read_return;
	static char buf[BUFFER_SIZE];

	if (fd <= 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	read_return = 1;
	while (read_return)
	{
//		printf("tour de boucle while\n");
		read_return = read(fd, buf, BUFFER_SIZE);
		printf("buf = %s\n", buf);
	}

	printf("read_return = %d\n", read_return);
	*line = NULL;
	return (read_return);
	//return = 1 : une ligne a ete lue
	//return = 0 : La lecture est terminee
	//return = -1 : une erreur est survenue
}
