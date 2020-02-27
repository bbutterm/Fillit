/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 17:48:25 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/05 17:48:27 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static	size_t	ft_strlen(const char *string)
{
	int counter;

	counter = 0;
	while (*string++ != '\0')
		counter++;
	return (counter);
}

void			ft_putstr(char *s1)
{
	if (!s1)
		return ;
	write(1, s1, ft_strlen(s1));
	free(s1);
}
