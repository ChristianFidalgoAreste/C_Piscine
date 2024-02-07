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

#include <stdlib.h>
#include "../inc/map.h"

void	free_info_map(int **ptr_to_free, int size)
{
	int	i;

	if (ptr_to_free)
	{
		i = 0;
		while (i < size)
			if (ptr_to_free[i])
				free(ptr_to_free[i++]);
		free(ptr_to_free);
	}
}

void	free_map(t_map *map)
{
	int	i;

	if (map->lines)
	{
		i = 0;
		while (i < map->size)
			if (map->lines[i])
				free(map->lines[i++]);
		free(map->lines);
	}
}

void	free_all(t_map *map, int **info_map)
{
	free_info_map(info_map, map->size);
	free_map(map);
}
