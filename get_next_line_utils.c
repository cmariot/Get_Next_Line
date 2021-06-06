/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:36:20 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/06 17:49:06 by cmariot          ###   ########.fr       */
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

char	*ft_strdup(const char *s1)
{
	int		src_len;
	char	*src;
	char	*cpy;
	int		i;

	src = (char *)s1;
	src_len = ft_strlen(src);
	cpy = malloc(sizeof(char) * (src_len + 1));
	if (!cpy)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		cpy[i] = s1[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
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

char	*ft_strchr(const char *s, int c)
{
	char	*str;
	int		i;

	if ((char)c < 0 || (char)c > 127)
		return (NULL);
	str = (char *)s;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (char)c)
			return (&str[i]);
		i++;
	}
	if (str[i] == '\0' && (char)c == '\0')
		return (&str[i]);
	return (NULL);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t dst_size)
{
	size_t	i;

	i = 0;
	if (!src || !dest)
		return (0);
	if (dst_size)
	{
		while (src[i] && i < dst_size - 1)
		{
			dest[i] = src[i];
			i++;
		}
		dest[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	new_len;

	if (s == NULL)
		return (NULL);
	if ((unsigned int)ft_strlen(s) < start)
		return (ft_strdup(""));
	new_len = ft_strlen(s + start);
	if (new_len < len)
		len = new_len;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, (s + start), (len + 1));
	return (str);
}

void	ft_strdel(char **ptr_str)
{
	if (ptr_str != NULL && *ptr_str != NULL)
	{
		free(*ptr_str);
		*ptr_str = NULL;
	}
}

/*void	ft_memdel(void **ptr_str)
{
	if (ptr_str != NULL)
	{
		free(*ptr_str);
		*ptr_str = NULL;
	}
}



int	main(int argc, char **argv)
{
	int	file_descriptor;
	char	*line;
	int	read_return;

	if (argc == 1)
	{
		file_descriptor = 1;
		line = NULL;
		read_return = get_next_line(file_descriptor, &line);
		printf("Ligne : %s", line);
		printf(" Retour : %d \n-------------------------------\n", read_return);
	}
	if (argc == 2)
	{
		file_descriptor = open(argv[1], O_RDWR);
		if (file_descriptor == -1)
		{
			printf("Erreur d'ouverture du fichier");
			return (0);
		}
		line = NULL;
		read_return = 1;
		while (read_return != 0)
		{
			read_return = get_next_line(file_descriptor, &line);
			printf("Ligne : %s", line);
			printf(" Retour : %d \n-------------------------------\n", read_return);
		}
		return (0);
	}
	else
	{
		printf("Il n'y a pas le bon nombre d'arguments");
		return (0);
	}
}*/
