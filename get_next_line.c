/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:18:47 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/08 15:32:51 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h" 

char	*ft_strdup(char *s1)
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

void	new_str(char **str, void *buf)
{
	char	*tmp;

	tmp = ft_strjoin(*str, buf);
	ft_strdel(str);
	*str = tmp;
}

int	get_next_line(int fd, char **line)
{
	static char	*str;
	char		buf[BUFFER_SIZE + 1];
	int			read_return;

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
			new_str(&str, buf);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (gnl_outpout(read_return, &str, line));
}
