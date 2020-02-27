/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bzero.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/05 18:47:36 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/05 18:47:38 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "fillit.h"

void	ft_bzero(void *destination, size_t n)
{
	char *dest;

	dest = destination;
	while (n--)
		*dest++ = '\0';
}
