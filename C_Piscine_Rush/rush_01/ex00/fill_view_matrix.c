/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_view_matrix.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 17:19:31 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/29 17:19:33 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

char	**fill_view_matrix(char *str, int size)
{
	int		i;
	int		j;
	char	**view_matrix;

	i = 0;
	view_matrix = malloc(4 * sizeof(char *));
	while (i < size)
		view_matrix[i++] = malloc(size * sizeof(char));
	i = 0;
	while (*str != '\0')
	{
		if (*str != ' ' && i++ % size == 0)
		{
			j = 0;
			while (j++ < size * 2)
			{
				if (str[j - 1] != ' ' && str[j - 1] != '\0')
					view_matrix[i / size][j / 2] = str[j - 1];
			}
		}
		str++;
	}
	return (view_matrix);
}
