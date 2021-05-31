/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/31 18:10:28 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	get_next_line(int fd, char **line)
{
	int read_return;
	char buf[BUFFER_SIZE + 1];
	static char *str;
	char *tmp;
	int len;

	if (fd <= 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	read_return = 1;
	while (read_return)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		buf[read_return] = '\0';
		if (str == NULL)
		{
			str = ft_strdup(buf);
		}
		else
		{
			tmp = ft_strjoin(str, buf);
			free(str);
			str = tmp;
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	if (read_return < 0)
		return (-1);
	else if (read_return == 0 && str == NULL)
		return (0);
	else
	{
		len = 0;
		while (str[len] != '\n' && str[len] != '\0')
			len++;
		if (str[len] == '\n')
		{
			*line = ft_substr(str, 0, len);
			tmp = ft_strdup(&str[len + 1]);
			free(str);
			str = tmp;
			if (*str == '\0')
				ft_strdel(&str);
		}
		else
		{
			*line = ft_strdup(str);
			ft_strdel(&str);
			return (0);
		}
	}
	return (1);
	//return = 1 : une ligne a ete lue
	//return = 0 : La lecture est terminee
	//return = -1 : une erreur est survenue
}
