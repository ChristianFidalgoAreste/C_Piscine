/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   use_args.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:55:43 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:55:45 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../inc/map.h"

void	init_maps(int size, t_maps *maps);
void	init_map(int size, t_map *map);
void	put_map(t_maps *maps, t_map *map, int i);
void	*ft_malloc(unsigned long size);
void	file_error(void);
long	ft_atoi(char *str);
int		fill_map_attrs(char *attributes, int size, t_map *map);
void	augment_str_size(char *str);
void	calculate_solution(t_map *map);
int		map_line_char_incorrect(t_map *map, char val);

int	retrieve_map_attributes(int fd, t_map *map)
{
	char	attributes[10 * sizeof(char *)];
	int		i;

	i = 0;
	while (read(fd, attributes + i, 1) > 0 && attributes[i] != '\n')
	{
		if (attributes[i] < 32 || attributes[i] >= 127)
		{
			map->is_valid = 0;
			return (0);
		}
		i++;
	}
	return (fill_map_attrs(attributes, i, map));
}

void	init_map_lines(int fd, t_map *map)
{
	char	*line;
	int		i;

	map->lines = malloc(sizeof(char *) * map->size);
	line = malloc(sizeof(char *));
	i = 0;
	while (read(fd, line + i, 1) > 0 && line[i] != '\n')
	{
		if (map_line_char_incorrect(map, line[i]))
		{
			map->is_valid = 0;
		}
		augment_str_size(line);
		i++;
	}
	map->line_size = i;
	map->lines[0] = line;
}

void	fill_lines(int fd, t_map *map)
{
	int		i;
	int		j;

	init_map_lines(fd, map);
	i = 1;
	while (i < map->size)
	{
		map->lines[i] = malloc(sizeof(char *) * map->line_size);
		j = 0;
		while (map->is_valid && j <= map->line_size)
		{
			if (read(fd, map->lines[i] + j, 1) < 0
				|| map_line_char_incorrect(map, map->lines[i][j]))
				map->is_valid = 0;
			j++;
		}
		j--;
		if (!map->is_valid || map->lines[i][j] != '\n')
			map->is_valid = 0;
		else
			map->lines[i][j] = '\0';
		i++;
	}
}

t_map	*create_map_by_route(char *route)
{
	t_map	*map;
	int		fd;

	map = ft_malloc(sizeof(t_map));
	fd = open(route, O_RDONLY);
	if (!fd)
		file_error();
	if (!retrieve_map_attributes(fd, map))
		return (map);
	fill_lines(fd, map);
	close(fd);
	return (map);
}

void	use_args(t_maps *maps, char **argv)
{
	int		i;
	t_map	*map;

	i = 1;
	while (i <= maps->size)
	{
		map = create_map_by_route(argv[i]);
		put_map(maps, map, i - 1);
		calculate_solution(map);
		if (i < maps->size)
			write(1, "\n", 1);
		free(map);
		i++;
	}
}
