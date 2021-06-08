/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/08 14:43:12 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <stdio.h>

int	gnl_outpout(int read_return, char **str, char **line)
{
	int		len;
	char	*tmp;

	if (read_return < 0)
		return (-1);
	else if (read_return == 0 && *str == NULL)
		return (0);
	len = 0;
	while ((*str)[len] != '\n' && (*str)[len] != '\0')
		len++;
	if ((*str)[len] == '\n')
	{
		*line = ft_substr(*str, 0, len);
		tmp = ft_strdup(&(*str)[len + 1]);
		ft_strdel(str);
		*str = tmp;
		if ((*str)[0] == '\0')
			ft_strdel(str);
		return (1);
	}
	*line = ft_strdup(*str);
	ft_strdel(str);
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			read_return;
	char		*tmp;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	read_return = 1;
	while (read_return)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
			return (-1);
		buf[read_return] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			tmp = ft_strjoin(str, buf);
			free(str);
			str = tmp;
		}
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (gnl_outpout(read_return, &str, line));
}
