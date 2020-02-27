/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   val.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/10 17:53:23 by mmarti            #+#    #+#             */
/*   Updated: 2019/05/10 17:53:26 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	check_sym(char *buf)
{
	int		i;
	size_t	n_c;
	size_t	sharp_c;

	i = 0;
	sharp_c = 0;
	n_c = 0;
	while (buf[i] != 0)
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (0);
		if (buf[i] == '#')
			sharp_c++;
		if (buf[i] == '\n')
			n_c++;
		i++;
	}
	if (sharp_c != 4 || buf[4] != '\n' || buf[9] != '\n' || n_c > 5 ||
		buf[14] != '\n' || buf[19] != '\n' || (buf[20] != '\n' && buf[20] != 0))
		return (0);
	else
		return (1);
}

static int	check_links(char *buf)
{
	int i;
	int links;

	i = 0;
	links = 0;
	if (check_sym(buf) == 0)
		return (0);
	while (buf[i] != 0)
	{
		if (buf[i] == '#')
		{
			if (i - 1 >= 0 && buf[i - 1] == '#')
				links++;
			if (i - 5 >= 0 && buf[i - 5] == '#')
				links++;
			if (i + 5 <= 19 && buf[i + 5] == '#')
				links++;
			if (buf[i + 1] == '#')
				links++;
		}
		i++;
	}
	if (links < 6)
		return (0);
	return (1);
}

int			check_val(int fd)
{
	char	buf[22];
	size_t	count;
	int		ret;
	int		tmp;

	tmp = 0;
	ret = 1;
	count = 0;
	ft_bzero(buf, 22);
	while ((ret = read(fd, buf, 21)))
	{
		tmp = ret;
		if (check_links(buf) == 0)
			return (0);
		count++;
		ft_bzero(buf, 21);
	}
	if (tmp != 20)
		return (0);
	return (count);
}
