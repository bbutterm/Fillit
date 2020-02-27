/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:30:19 by mmarti            #+#    #+#             */
/*   Updated: 2019/06/25 17:30:22 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int		down(int *shape, int lastpos)
{
	int i;

	i = 0;
	if (cord_max(shape) + shape[5] > lastpos)
		return (-1);
	while (shape[i] != -1)
		shape[i++] += shape[5];
	return (0);
}

static	int		shift(int *shape, int base, int lastpos)
{
	int i;

	i = 0;
	while (shape[i] != -1)
	{
		if ((shape[i] + 1) % base == 0)
			return (down(shape, lastpos));
		++i;
	}
	while (*shape != -1)
		*shape++ += 1;
	return (0);
}

static	int		compare_shapes(int **res, int j)
{
	int j2;
	int i;
	int i2;

	i = 0;
	i2 = 0;
	j2 = j - 1;
	while (i < 4)
	{
		while (j2 >= 0)
		{
			if (res[j][i] == res[j2][i2])
				return (-1);
			i2++;
			if (i2 >= 4)
			{
				j2--;
				i2 = 0;
			}
		}
		i++;
		j2 = j - 1;
	}
	return (0);
}

static	void	reset(int *res)
{
	int r;
	int i;

	i = 0;
	r = res[0] - res[7];
	while (res[i] != -1)
		res[i++] -= r;
}

int				algorithm(int **shapes, int base, int lastpos)
{
	int curr;
	int tmp;

	tmp = 0;
	curr = 1;
	while (shapes[curr])
	{
		while (compare_shapes(shapes, curr) < 0 && tmp >= 0)
			tmp = shift(shapes[curr], base, lastpos);
		if (tmp == 0)
			curr++;
		else if (tmp == -1)
		{
			reset(shapes[curr]);
			if (--curr < 0)
				return (-1);
			tmp = shift(shapes[curr], base, lastpos);
		}
	}
	return (0);
}
