/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/12 16:23:52 by mmarti            #+#    #+#             */
/*   Updated: 2019/05/12 16:23:54 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	int			get_miny(char **tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tmp[j][i] != '#')
	{
		j++;
		if (tmp[j] == 0)
		{
			i++;
			j = 0;
		}
	}
	return (i);
}

static int			get_minx(char **tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tmp[j][i] != '#')
	{
		i++;
		if (i == 4)
		{
			j++;
			i = 0;
		}
	}
	return (j);
}

static	int			*convert(int *masx, int *masy, int x_min, int y_min)
{
	int i;
	int *result;

	i = 0;
	masx[4] = -1;
	masy[4] = -1;
	if (!(result = (int *)malloc(sizeof(int) * 8)))
		return (0);
	while (i < 4)
	{
		masx[i] -= y_min;
		masy[i++] -= x_min;
	}
	i = -1;
	while (++i < 4)
		result[i] = masx[i] + masy[i] * 4;
	result[4] = -1;
	result[5] = cord_max(masx) + 1;
	result[6] = cord_max(masy) + 1;
	result[7] = result[0];
	return (result);
}

static	int			*get_params(char **tmp, int x_min, int y_min)
{
	int x;
	int y;
	int masx[5];
	int masy[5];
	int i;

	x = 0;
	y = 0;
	i = 0;
	while (i < 4)
	{
		if (tmp[y][x] == '#')
		{
			masx[i] = x;
			masy[i++] = y;
		}
		x++;
		if (x >= 4)
		{
			y++;
			x = 0;
		}
	}
	freestr(tmp);
	return (convert(masx, masy, x_min, y_min));
}

int					*split(int fd)
{
	char	buf[22];
	char	**tmp;
	int		x_min;
	int		y_min;

	ft_bzero(buf, 22);
	if (read(fd, buf, 21) > 0)
	{
		tmp = ft_strsplit(buf, '\n');
		ft_bzero(buf, 22);
		x_min = get_minx(tmp);
		y_min = get_miny(tmp);
		return (get_params(tmp, x_min, y_min));
	}
	return (0);
}
