/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_conditions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:54:43 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:54:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

int	check_attrs_valid(t_map *map)
{
	map->is_valid = map->size > 0
		&& map->full != map->empty
		&& map->full != map->obstacle
		&& map->empty != map->obstacle;
	return (map->is_valid);
}

int	map_line_char_incorrect(t_map *map, char val)
{
	return (val != map->empty
		&& val != map->full
		&& val != map->obstacle
		&& val != '\n');
}
