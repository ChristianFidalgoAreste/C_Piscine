/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_value.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:29:33 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/04 22:29:36 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include "../deps/memory_to_be_freed.h"

int		count_file_lines(int fd);
int		*calculate_length_of_lines(long size, int fd);
int		dict_error(void);
int		error(void);
long	*create_ass_keys(long size, char **lines_tab);
char	**create_ass_values(long size, char **lines_tab);
void	free_memory(void);
long	ft_atoi(char *str);
int		decomp_arg(long n, long *key_array, char **value_array);

void	give_values_to_tab(char **lines_tab, int *lengths_tab, int fd)
{
	int	i;

	i = 0;
	while (lines_tab[i] != 0 && read(fd, lines_tab[i], lengths_tab[i]))
	{
		lines_tab[i][lengths_tab[i] - 1] = '\0';
		i++;
	}
	i = 0;
}

char	**create_lines_tab(long size, int fd, char *dict_route)
{
	char	**lines_tab;
	int		*lengths_tab;
	long	i;

	lines_tab = malloc((size + 1) * sizeof(char *));
	lengths_tab = calculate_length_of_lines(size, fd);
	if (!lines_tab || !lengths_tab)
		return (NULL);
	// g_mem_to_free.lines_tab = lines_tab;
	i = 0;
	while (i < size)
	{
		lines_tab[i] = malloc(lengths_tab[i] * sizeof(char));
		if (!lines_tab[i])
			break ;
		i++;
	}
	close (fd);
	fd = open(dict_route, O_RDONLY);
	if (fd == -1)
		return (0);
	//TO-DO: Method to free lines_tab[i], lines_tab	an lengths_table
	//And TRYING not to close and open the file here, but on the main method
	lines_tab[i] = 0;
	give_values_to_tab(lines_tab, lengths_tab, fd);
	return (lines_tab);
}

int	check_argv(char *value)
{
	if (ft_atoi(value) > UINT_MAX)
		return (-1);
	return (1);
}


int	read_value(char *dict_route, char *value)
{
	int		fd;
	long	size;
	char	**lines_tab;
	long	*key_array;
	char	**value_array;

	if (check_argv(value) == -1)
		return (error());
	fd = open(dict_route, O_RDONLY);
	if (fd == -1)
		return (dict_error());
	size = count_file_lines(fd);
	// g_mem_to_free.size = size;
	close(fd);
	fd = open(dict_route, O_RDONLY);
	if (fd == -1)
		return (dict_error());
	lines_tab = create_lines_tab(size, fd, dict_route);
	close(fd);
	key_array = create_ass_keys(size, lines_tab);
	value_array = create_ass_values(size, lines_tab);
	if (ft_atoi(value) == -1)
		return (error());
	size = decomp_arg(ft_atoi(value), key_array, value_array);
	if (!size)
		return (1);
	write(1, "\n", 1);
	free_memory();
	return (0);
}
