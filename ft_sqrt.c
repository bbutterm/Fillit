/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/22 19:52:33 by mmarti            #+#    #+#             */
/*   Updated: 2019/06/22 19:52:47 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int n;
	int counter;

	if (nb == 0)
		return (0);
	n = 42;
	counter = 0;
	while (counter++ < 20)
	{
		if (n * n == nb)
			return (n);
		n = (n + nb / n) / 2;
	}
	return (ft_sqrt(++nb));
}
