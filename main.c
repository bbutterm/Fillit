/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/25 17:49:43 by mmarti            #+#    #+#             */
/*   Updated: 2019/06/25 17:49:45 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	**change_cords(int **cords, int base, int newbase)
{
	int i;
	int j;

	if (base == newbase)
		return (cords);
	i = 0;
	j = 0;
	while (cords[j] != 0)
	{
		cords[j][i] += (newbase - base) * (cords[j][i] / base);
		i++;
		if (i >= 4)
		{
			cords[j][7] = cords[j][0];
			i = 0;
			j++;
		}
	}
	return (cords);
}

int	validation(char *fname)
{
	int fd;
	int ammount;

	fd = open(fname, O_RDONLY);
	if (fd < 0)
		return (0);
	ammount = check_val(fd);
	close(fd);
	return (ammount);
}

int	**record(int ammount, char *fname)
{
	int **res;
	int fd;
	int i;

	i = 0;
	fd = open(fname, O_RDONLY);
	if (!(res = (int **)malloc(sizeof(int *) * (ammount + 1))) || fd < 0)
		return (0);
	while (ammount--)
		res[i++] = split(fd);
	res[i] = 0;
	close(fd);
	return (res);
}

int	getbase(int ammount, int **sharps)
{
	int base;
	int i;

	i = 0;
	base = ft_sqrt(ammount * 4);
	while (sharps[i] != 0)
	{
		if (sharps[i][5] > base)
			base = sharps[i][5];
		if (sharps[i][6] > base)
			base = sharps[i][6];
		++i;
	}
	return (base);
}

int	main(int argc, char **argv)
{
	int ammount;
	int **sharps;
	int base;
	int lastpos;

	if (argc != 2)
		write(1, "usage: ./fillit target_filename\n", 32);
	ammount = validation(argv[1]);
	if (ammount == 0 || ammount > 26)
	{
		write(1, "error\n", 6);
		return (0);
	}
	sharps = record(ammount, argv[1]);
	base = getbase(ammount, sharps);
	lastpos = base * base - 1;
	sharps = change_cords(sharps, 4, base);
	while (algorithm(sharps, base, lastpos) < 0)
	{
		base++;
		lastpos = base * base - 1;
		sharps = change_cords(sharps, base - 1, base);
	}
	ft_putstr(write_string(sharps, base));
	return (0);
}
