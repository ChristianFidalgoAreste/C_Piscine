/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:55:00 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:55:02 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

#ifndef ATTRIBUTES_MIN_SIZE
# define ATTRIBUTES_MIN_SIZE 4
#endif

void	memory_error(void);
void	*ft_malloc(unsigned long size);
long	ft_atoi(char *str);
int		check_attrs_valid(t_map *map);

void	init_maps(int size, t_maps *maps)
{
	maps->size = size;
	maps->list = ft_malloc(sizeof(t_map) * size);
}

void	put_map(t_maps *maps, t_map *map, int i)
{
	if (maps && map && i >= 0)
	{
		if (i < maps->size)
			maps->list[i] = *map;
	}
}

void	init_map(int size, t_map *map)
{
	map->is_valid = -1;
	map->size = size;
	map->lines = ft_malloc(sizeof(char *) * size);
}

int	fill_map_attrs(char *attributes, int size, t_map *map)
{
	map->is_valid = size >= ATTRIBUTES_MIN_SIZE;
	if (!map->is_valid)
		return (0);
	map->full = attributes[--size];
	map->obstacle = attributes[--size];
	map->empty = attributes[--size];
	attributes[size] = '\0';
	map->size = ft_atoi(attributes);
	map->is_valid = check_attrs_valid(map);
	return (map->is_valid);
}
