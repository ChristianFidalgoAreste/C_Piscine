/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   papa.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 15:03:16 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/29 15:03:19 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_matrix(int size, char **matrix);
int		ft_strlen(char *str);
int		check_papa(char **matrix, char **view, int i, int j);

int	papa(char **matrix, char **view, int i, int j)
{
	int	size;

	size = ft_strlen(matrix[0]);
	if (matrix[i][j] - '0' < size)
		matrix[i][j]++;
	else if (matrix[i][j] == size + '0')
	{
		if (j == 0 && i == 0)
			return (0);
		else if (j == 0 && i > 0)
			return (papa(matrix, view, --i, size - 1));
		else
			return (papa(matrix, view, i, --j));
	}
	if (check_papa(matrix, view, i, j))
	{
		if (i == size - 1 && j == size - 1)
			return (1);
		else if (j == size - 1)
			return (papa(matrix, view, ++i, 0));
		else
			return (papa(matrix, view, i, ++j));
	}
	else
		return (papa(matrix, view, i, j));
}
