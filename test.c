/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/07 17:14:06 by cmariot           #+#    #+#             */
/*   Updated: 2021/06/07 18:32:31 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int len;

	len = 0;
	while (*str++)
		len++;
	return (len);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, &*str++, 1);
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

int fct2(char ***line, char **str)
{
	**line = ft_strdup(*str);
	return (1);
}

int fct1(char **line)
{
	char *str;

	str = ft_strdup("tutu");
	*line = ft_strdup("tata");
	fct2(&line, &str);
	return (1);
}


int	main(void)
{
	char *line;

	line = ft_strdup("toto");
	fct1(&line);
	ft_putstr(line);
	return (0);
}
