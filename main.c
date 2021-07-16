/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:42:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/07/12 00:05:19 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		file_descriptor;
	char	*str;

	if (argc == 2)
	{
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			printf("Erreur d'ouverture du fichier");
			return (-1);
		}
		str = get_next_line(file_descriptor);
		printf("%s", str);
		while (str)
		{
			str = get_next_line(file_descriptor);
			printf("%s", str);
			free(str);
		}
		return (0);
	}
	printf("Il n'y a pas le bon nombre d'arguments");
	return (-1);
}
