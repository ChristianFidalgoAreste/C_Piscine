/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_from_input.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:55:10 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:55:12 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "../inc/map.h"

int		ft_strlen(char *str);
void	*ft_malloc(unsigned long size);
void	fill_map_attrs(char *attributes, int size, t_map *map);
void	augment_str_size(char *str);
void	calculate_solution(t_map *map);
int		map_line_char_incorrect(t_map *map, char val);

int	check_map_char(t_maps *maps, char ch)
{
	if (maps->list->empty != ch && maps->list->obstacle != ch)
		return (0);
	return (1);
}

void	read_info_line(t_maps *maps)
{
	char	*line;
	char	aux;
	int		i;

	i = 0;
	aux = ' ';
	line = ft_malloc(12 * sizeof(char));
	while (aux != '\n')
	{
		read(STDIN_FILENO, &aux, 1);
		if (i < 12)
			line[i] = aux;
		i++;
	}
	if (i > 12)
		maps->list->is_valid = 0;
	else
		fill_map_attrs(line, --i, maps->list);
	free(line);
}

void	read_fl_map(t_maps *maps)
{
	char	*line;
	int		i;

	maps->list->lines = ft_malloc(sizeof(char *) * maps->list->size);
	line = ft_malloc(sizeof(char *));
	i = 0;
	while (read(STDIN_FILENO, line + i, 1) > 0 && line[i] != '\n')
	{
		if (map_line_char_incorrect(maps->list, line[i]))
			maps->list->is_valid = 0;
		augment_str_size(line);
		i++;
	}
	maps->list->line_size = i;
	maps->list->lines[0] = line;
}

int	read_whole_map(t_maps *maps, int i, int j)
{
	char	aux;

	while (i < maps->list->size)
		maps->list->lines[i++] = ft_malloc((maps->list->line_size + 1)
				* sizeof(char));
	i = 1;
	while (i < maps->list->size)
	{
		j = 0;
		aux = ' ';
		while (aux != '\n')
		{
			if (read(STDIN_FILENO, &aux, 1) < 0
				|| map_line_char_incorrect(maps->list, aux))
				maps->list->is_valid = 0;
			if (j < maps->list->line_size)
				maps->list->lines[i][j] = aux;
			j++;
		}
		if (j != maps->list->line_size + 1)
			return (0);
		i++;
	}
	return (maps->list->is_valid);
}

void	read_from_input(t_maps *maps)
{
	maps->size = 1;
	read_info_line(maps);
	if (!maps->list->is_valid)
		return ;
	read_fl_map(maps);
	if (!maps->list->line_size)
		return ;
	maps->list->is_valid = read_whole_map(maps, 1, 0);
	write(STDOUT_FILENO, "\n", 1);
	close(STDIN_FILENO);
	calculate_solution(maps->list);
}
