/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:26:22 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/07 18:26:22 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"
#include "../inc/square.h"

void	set_square(t_square *square, int size, int i, int j);
void	*ft_malloc(unsigned long size);

void	fill_info_map(t_map *map, int **info_map, t_square *square)
{
	int	i;
	int	j;
	int	min;

	i = 1;
	while (i < map->size)
	{
		j = 1;
		while (j < map->line_size)
		{
			if (map->lines[i][j] != map->obstacle)
			{
				min = info_map[i - 1][j - 1];
				if (min > info_map[i - 1][j])
					min = info_map[i - 1][j];
				else if (min > info_map[i][j - 1])
					min = info_map[i][j - 1];
				info_map[i][j] = min + 1;
				if (square->size < info_map[i][j])
					set_square(square, info_map[i][j], i, j);
			}
			j++;
		}
		i++;
	}
}

void update_info_map(int **info_map, t_square *square, int i, int j)
{
	info_map[i][j] = 1;
	if (square->size == 0)
		set_square(square, 1, i, j);
}

void	init_info_map(t_map *map, int **info_map, t_square *square)
{
	int	i;

	i = 0;
	while (i < map->line_size)
	{
		if (map->lines[0][i] == map->empty)
			update_info_map(info_map, square, 0, i);
		else
			info_map[0][i] = 0;
		i++;
	}
	i = 0;
	while (i < map->size)
	{
		if (map->lines[i][0] == map->empty)
			update_info_map(info_map, square, i, 0);
		else
			info_map[i][0] = 0;
		i++;
	}
}

int	**create_info_map(t_map *map, t_square *square)
{
	int	**info_map;
	int	i;

	i = 0;
	info_map = ft_malloc(map->size * sizeof(int *));
	while (i < map->size)
		info_map[i++] = ft_malloc(map->line_size * sizeof(int));
	init_info_map(map, info_map, square);
	return (info_map);
}
