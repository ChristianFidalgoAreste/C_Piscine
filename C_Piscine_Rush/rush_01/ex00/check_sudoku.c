/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sudoku.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:18:38 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/29 15:18:40 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strlen(char *str);

int	check_sudoku_y(char **matrix)
{
	int	i;
	int	j;
	int	k;
	int	size;

	size = ft_strlen(*matrix);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && matrix[j][i] != '0')
		{
			k = j + 1;
			while (k < size)
			{
				if (matrix[j][i] == matrix[k][i])
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sudoku_x(char **matrix)
{
	int	i;
	int	j;
	int	k;
	int	size;

	size = ft_strlen(*matrix);
	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size && matrix[i][j] != '0')
		{
			k = j + 1;
			while (k < size)
			{
				if (matrix[i][j] == matrix[i][k])
					return (0);
				k++;
			}
			j++;
		}
		i++;
	}
	return (1);
}

int	check_sudoku(char **matrix)
{
	return (check_sudoku_x(matrix) && check_sudoku_y(matrix));
}
