/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_solution.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:36:34 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/07 12:47:28 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "../inc/map.h"
#include "../inc/square.h"

void	fill_info_map(t_map *map, int **info_map, t_square *square);
int		**create_info_map(t_map *map, t_square *square);
void	free_all(t_map *map, int **info_map);
void	set_square(t_square *square, int size, int i, int j);

void	print_map(t_map *map, t_square *square)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->size)
	{
		j = 0;
		while (j < map->line_size)
		{
			if (i >= square->i - (square->size - 1) && i <= square->i
				&& j >= square->j - (square->size - 1) && j <= square->j)
				write(STDOUT_FILENO, &map->full, 1);
			else
				write(STDOUT_FILENO, map->lines[i] + j, 1);
			j++;
		}
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

void	calculate_solution(t_map *map)
{
	t_square	square;
	int			**info_map;

	if (!map->is_valid)
	{
		write(STDERR_FILENO, "map error\n", 10);
		free_all(map, NULL);
		return ;
	}
	set_square(&square, 0, 0, 0);
	info_map = create_info_map(map, &square);
	fill_info_map(map, info_map, &square);
	print_map(map, &square);
	free_all(map, info_map);
}

void	calculate_solutions(t_maps *maps)
{
	int	i;

	i = 0;
	while (i < maps->size)
	{
		calculate_solution(maps->list + i++);
		write(1, "\n", 1);
	}
}
