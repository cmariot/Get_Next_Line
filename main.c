/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:42:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/10 16:37:42 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int argc, char **argv)
{
	int		file_descriptor;
	int		line_read;
	char	*str;

	if (argc == 1)
	{
		str = get_next_line(1);
		printf("Ligne : %s", str);
		free(str);
		return (0);
	}
	if (argc == 2 )
	{
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			printf("Erreur d'ouverture du fichier");
			return (-1);
		}
		line_read = 14;
		while (line_read--)
		{
			str = get_next_line(file_descriptor);
			printf("Ligne : %s", str);
			free(str);
		}
		return (0);
	}
	else
		printf("Il n'y a pas le bon nombre d'arguments");
	return (-1);
}
