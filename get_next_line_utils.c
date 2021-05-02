/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:36:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/04/30 18:38:44 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	int		s1_size;
	int		s2_size;
	char	*str;

	if (!s1 || !s2)
		return (NULL);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	str = malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (str == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		str[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}


int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	*line;
	int	read_return;
	int	i;

	if (argc == 2 )
	{
		file_descriptor = open(argv[1], O_RDONLY);
		if (file_descriptor == -1)
		{
			printf("Erreur d'ouverture du fichier");
			return (0);
		}
		i = 0;
		line = NULL;
		read_return = get_next_line(file_descriptor, &line);
		printf("Ligne %d : %s\n", i++, line);
		printf("Retour :%d\n", read_return);
		
		//	free(line);
		printf("Lecture terminee.\n");
		return (0);
	}
	else
	{
		printf("Il n'y a pas le bon nombre d'arguments");
		return (0);
	}
}
