/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 05:38:03 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/29 05:38:07 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**fill_matrix(int size)
{
	char	**matrix;
	int		i;
	int		j;

	i = 0;
	j = 0;
	matrix = malloc(size * sizeof(char *));
	while (i < size)
		matrix[i++] = malloc(size * sizeof(char));
	i = 0;
	while (i < size)
	{
		while (j < size)
			matrix[i][j++] = '0';
		i++;
		j = 0;
	}
	return (matrix);
}
