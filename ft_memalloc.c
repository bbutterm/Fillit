/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmarti <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/15 17:58:05 by mmarti            #+#    #+#             */
/*   Updated: 2019/04/15 17:58:06 by mmarti           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "fillit.h"

void	*ft_memalloc(size_t size)
{
	void *c;

	if (!size)
		return (NULL);
	c = (void *)malloc(size);
	if (!c)
		return (0);
	ft_bzero(c, size);
	return (c);
}
