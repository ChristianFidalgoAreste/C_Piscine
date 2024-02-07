/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_file_lines.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:28:22 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/04 22:28:25 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include "../deps/memory_to_be_freed.h"

int	dict_error(void);

int	count_file_lines(int fd)
{
	char	aux[1];
	char	last[1];
	int		text_has_content;
	int		count;
	count = 0;
	text_has_content = 1;
	while (text_has_content)
	{
		text_has_content = read(fd, &aux[0], 1);
		if (text_has_content == -1)
			return (dict_error());
		if (text_has_content)
			last[0] = aux [0];
		if (text_has_content && aux[0] == '\n')
			count++;
		else if (!text_has_content && last[0] != '\n')
			count++;
	}
	return (count);
}

int	calculate_length_of_lines_part_2(int fd)
{
	char	aux[1];
	int		j;
	int		read_v;
	aux[0] = '0';
	j = 0;
	while (aux[0] != '\n')
	{
		read_v = read(fd, &aux[0], 1);
		if(read_v)
			j++;
		else
		{
			j++;
			break ;
		}
	}
	return (j);
}
int	*calculate_length_of_lines(long size, int fd)
{
	char	aux[1];
	int		*lengths_tab;
	int		i;
	int		j;
	lengths_tab = malloc(size * sizeof(int));
	if (!lengths_tab)
		return (NULL);
	// g_mem_to_free.lengths_tab = lengths_tab;
	aux[0] = '0';
	i = 0;
	while (i < size)
	{
		j = calculate_length_of_lines_part_2(fd);
		aux[0] = '0';
		lengths_tab[i++] = j;
	}
	return (lengths_tab);
} 