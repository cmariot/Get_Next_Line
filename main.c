/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/10 14:42:51 by cmariot           #+#    #+#             */
/*   Updated: 2021/08/26 00:48:02 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int	main(int argc, char **argv)
{
	int		file_descriptor;
	char	*str;
	
	if (argc == 1)
	{
		while (1)
		{
			str = get_next_line(1);
			if (str == NULL)
				break ;
			printf("%s", str);
			free(str);
		}
	}
	else if (argc == 2)
	{
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
			return (-1);
		while (1)
		{
			str = get_next_line(file_descriptor);
			if (str == NULL)
				break ;
			printf("%s", str);
			free(str);
		}
		close(file_descriptor);
	}
	else
		printf("Il n'y a pas le bon nombre d'arguments");
	return (0);
}
