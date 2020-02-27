/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 22:05:19 by mmarti            #+#    #+#             */
/*   Updated: 2019/06/25 22:05:21 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	masfree(int **mass)
{
	int i;

	i = 0;
	while (mass[i] != 0)
		free(mass[i++]);
	free(mass[i]);
	free(mass);
}

void	freestr(char **str)
{
	int i;

	i = 0;
	while (str[i] != 0)
		free(str[i++]);
	free(str[i]);
	free(str);
}
