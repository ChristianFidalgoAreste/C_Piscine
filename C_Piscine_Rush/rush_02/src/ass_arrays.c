/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ass_arrays.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 22:25:20 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/04 22:25:22 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include "../deps/memory_to_be_freed.h"

int			ft_strlen(char *str);
long		ft_atoi(char *str);
int			ft_trim(char *str);

long	parse_key(char *line)
{
	char		*aux;
	long		i;
	long		num;

	i = 0;
	aux = malloc(ft_strlen(line) * sizeof(char));
	if (!aux)
		return (-1);
	while (line[i] >= '0' && line[i] <= '9')
	{
		aux[i] = line[i];
		i++;
	}
	aux[i] = '\0';
	num = ft_atoi(aux);
	free(aux);
	if (num == -1)
		return(-1);
	return (num);
}

long	*create_ass_keys(long size, char **lines_tab)
{
	long	*key_array;
	long	i;

	key_array = malloc(size * sizeof(long));
	if (!key_array)
		return (NULL);
	// g_mem_to_free.key_array = key_array;
	i = 0;
	while (i < size)
	{
		key_array[i] = parse_key(lines_tab[i]);
		i++;
	}
	return (key_array);
}

void	parse_values(char **lines, long size, char **value_array)
{
	long		i;
	long		j;
	char	*aux;
	int		trimmed_line_size;

	i = 0;
	while (i < size)
	{
		aux = lines[i];
		while (*(aux - 1) != ':')
			aux++;
		trimmed_line_size = ft_trim(aux);
		// TODO: Error handling
		if (!trimmed_line_size)
			printf("Nullado");
		value_array[i] = malloc(trimmed_line_size * sizeof(char));
		j = -1;
		while (aux[++j] != '\0')
			value_array[i][j] = aux[j];
		i++;
	}
	value_array[i] = NULL;
}

char	**create_ass_values(long size, char **lines_tab)
{
	char	**value_array;

	value_array = malloc((size + 1) * sizeof(char *));
	if (!value_array)
		return (NULL);
	// g_mem_to_free.value_array = value_array;
	parse_values(lines_tab, size, value_array);
	return (value_array);
}
