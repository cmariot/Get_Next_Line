/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 14:36:20 by cmariot           #+#    #+#             */
/*   Updated: 2022/06/28 04:41:16 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

char	*ft_strchr(const char *s, int c)
{
	char		*str;
	const char	to_find = (char)c;
	int			i;

	str = (char *)s;
	if (c < 0 || c > 127 || !s)
		return (NULL);
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == to_find)
			return (&str[i]);
		i++;
	}
	if (to_find == '\0')
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

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	nb_bytes;
	size_t	i;

	nb_bytes = size * count;
	new = malloc(nb_bytes);
	if (!new)
		return (NULL);
	i = 0;
	while (i < nb_bytes)
		((char *)new)[i++] = 0;
	return (new);
}
