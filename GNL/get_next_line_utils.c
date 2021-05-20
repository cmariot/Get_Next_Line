/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:54:21 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/20 12:21:45 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(int argc, char **argv)
{
	int fd;
	char **line;
	int ret;

	if (argc >= 2)
	{
		fd = open(argv[1], O_RDONLY);
		line = NULL;
		ret = get_next_line(fd, line);
		printf("%d\n", ret);
	}
	return (0);
}
