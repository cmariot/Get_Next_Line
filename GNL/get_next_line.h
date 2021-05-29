/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 11:50:17 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/20 12:21:47 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_C
# define GET_NEXT_LINE_C

# include <unistd.h>
# include <stdlib.h>

int	get_next_line(int fd, char **line);

# endif
