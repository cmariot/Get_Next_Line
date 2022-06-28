/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/28 05:30:17 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 
#include <stdio.h>

char	*gnl_outpout(char **read_line)
{
	char	*line;
	int		len;
	char	*end;

	len = 0;
	while ((*read_line)[len] != '\0' && (*read_line)[len] != '\n')
		len++;
	if ((*read_line)[len] == '\n')
	{
		line = ft_substr(*read_line, 0, len + 1);
		end = ft_strdup(*read_line + (len + 1));
		free(*read_line);
		*read_line = end;
		return (line);
	}
	else if ((*read_line)[len] == '\0')
	{
		line = ft_strdup(*read_line);
		free(*read_line);
		return (line);
	}
	else
		return (ERROR);
}

void	add_buf_to_read_line(char **str, char *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	if (*str && **str)
		free(*str);
	*str = tmp;
}

char	*get_next_line(int fd)
{
	static char	*read_line;
	char		buf[BUFFER_SIZE + 1];
	ssize_t		read_return;
	char		*tmp;

	if (fd == -1 || BUFFER_SIZE == 0)
		return (ERROR);
	while (1)
	{
		read_return = read(fd, buf, BUFFER_SIZE);
		if (read_return == -1)
			return (ERROR);
		buf[read_return] = '\0';
		if (read_line == NULL)
			read_line = ft_strdup(buf);
		else
			add_buf_to_read_line(&read_line, buf);
		if (read_return == 0 || ft_strchr(read_line, '\n'))
			break ;
	}
	if (read_return == 0)
	{
		if (read_line)
		{
			tmp = ft_strdup(read_line);
			free(read_line);
			return (tmp);
		}
		return (END_OF_FILE);
	}
	else
		return (gnl_outpout(&read_line));
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*new;
	int		i;
	int		j;
	int		len;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = ft_calloc(len, sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		new[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j] != '\0')
		new[i++] = s2[j++];
	return (new);
}

char	*ft_strdup(const char *src)
{
	char	*new;
	int		src_len;
	int		i;

	src_len = ft_strlen(src);
	if (src_len == 0)
		return (NULL);
	new = ft_calloc(src_len + 1, sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < src_len)
	{
		new[i] = src[i];
		i++;
	}
	return (new);
}
