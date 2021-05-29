/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:36:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/29 14:12:30 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	*line;
	int	read_return;
	int	i;

	if (argc == 2 )
	{
		file_descriptor = open(argv[1], O_RDWR);
		if (file_descriptor == -1)
		{
			printf("Erreur d'ouverture du fichier");
			return (0);
		}
		i = 0;
		line = NULL;
		read_return = get_next_line(file_descriptor, &line);
//		printf("Ligne %d : %s\n", i++, line);
//		printf("Retour :%d\n", read_return);
		
		//	free(line);
//		printf("Lecture terminee.\n");
		return (0);
	}
	else
	{
		printf("Il n'y a pas le bon nombre d'arguments");
		return (0);
	}
}
