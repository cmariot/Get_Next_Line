/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_variables.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmariot <cmariot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 11:08:43 by cmariot           #+#    #+#             */
/*   Updated: 2021/05/31 13:41:01 by cmariot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int nb_appels(void)
{
	static int appel;

	appel++;
	return (appel);
}

char *static_char()
{
	static char *s = "test";

	return (s++);
}

int	main(void)
{

	printf("%d\n", nb_appels());	
	printf("%d\n", nb_appels());	
	printf("%d\n", nb_appels());	
	printf("%d\n", nb_appels());	
	
	printf("%s\n", static_char());	
	printf("%s\n", static_char());	
	printf("%s\n", static_char());	
	printf("%s\n", static_char());	
	return (0);
}
