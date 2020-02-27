/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbutterm <bbutterm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 17:23:03 by mmarti            #+#    #+#             */
/*   Updated: 2019/05/17 19:40:18 by bbutterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include <string.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

int			check_val(int fd);
int			*split(int fd);
int			**change_cords(int **cords, int base, int newbase);
int			cord_max(int *mas);
void		*ft_memalloc(size_t size);
void		ft_bzero(void *destination, size_t n);
int			ft_sqrt(int nb);
char		**ft_strsplit(char *s, int c);
char		*write_string(int **res, int base);
void		ft_putstr(char *s1);
int			algorithm(int **shapes, int base, int lastpos);
void		masfree(int **mass);
void		freestr(char **str);

#endif
