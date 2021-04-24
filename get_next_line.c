/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/24 17:08:58 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	int		read_return;
	//static char	*s;


	*line = "OK CA MARCHE";
	fd = 0;
	read_return = 1;
	//read_return = 1 : une ligne a ete lue
	//read_return = 0 : La lecture est terminee
	//read_return = -1 : une erreur est survenue
	return (read_return);
}
