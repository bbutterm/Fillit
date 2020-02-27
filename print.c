/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:50:21 by mmarti            #+#    #+#             */
/*   Updated: 2019/06/25 17:50:23 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char		*create_string(int base)
{
	char	*string;
	int		i;
	int		a;
	char	*tmp;

	a = 0;
	i = 0;
	string = (char *)ft_memalloc(base * base + base + 1);
	tmp = string;
	while (a < base)
	{
		while (i < base)
		{
			*string++ = '.';
			i++;
		}
		*string++ = '\n';
		a++;
		i = 0;
	}
	return (tmp);
}

char		*write_string(int **res, int base)
{
	char	*string;
	char	a;
	int		j;
	int		i;

	i = 0;
	j = 0;
	a = 'A';
	string = create_string(base);
	while (res[j] != 0)
	{
		while (res[j][i] != -1)
		{
			string[res[j][i] + res[j][i] / base] = a;
			i++;
		}
		j++;
		a++;
		i = 0;
	}
	masfree(res);
	return (string);
}
