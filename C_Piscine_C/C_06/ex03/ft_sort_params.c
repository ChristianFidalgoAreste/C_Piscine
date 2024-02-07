/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 06:22:55 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/10/30 15:59:49 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void	write_args(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i < argc)
	{
		while (argv[i][j] != '\0')
			write (1, &argv[i][j++], 1);
		write(1, "\n", 1);
		j = 0;
		i++;
	}
}

void	sort_args(int argc, char **argv, int i, int j)
{
	int		k;
	char	*temp;

	k = 0;
	while (i < argc - 1)
	{
		while (j < argc)
		{
			while (argv[i][k] == argv[j][k] && argv[i][k] != '\0'
				&& argv[j][k] != '\0')
				k++;
			if (argv[i][k] > argv[j][k])
			{
				temp = &argv[i][0];
				argv[i] = &argv[j][0];
				argv[j] = temp;
			}
			k = 0;
			j++;
		}
		i++;
		j = i + 1;
	}
}

int	main(int argc, char **argv)
{
	sort_args(argc, argv, 1, 2);
	write_args(argc, argv);
}
