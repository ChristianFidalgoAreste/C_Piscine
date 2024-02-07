/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 14:23:35 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/28 16:44:05 by prius-no         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	get_min(int size)
{
	return (2 * size - 1);
}

int	get_max(int size)
{
	int	i;
	int	counter;

	counter = 0;
	i = size;
	while (i > 0)
	{
		counter += i;
		i--;
	}
	return (counter);
}

int	arg_solvable(char *arg, int size)
{
	int		i;
	int		j;
	int		counter;

	i = 0;
	while (*arg != '\0')
	{
		if (*arg != ' ')
		{
			if (i++ % size == 0)
			{
				j = 0;
				counter = 0;
				while (j++ < size * 2)
				{
					if (arg[j - 1] != ' ' && arg[j - 1] != '\0')
						counter += (int) arg[j - 1] - '0';
				}
				if (counter > get_max(size) || counter < get_min(size))
					return (0);
			}
		}
		arg++;
	}
	return (1);
}

int	arg_acceptable(char *arg, int numbers_amount)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		if (arg[i] != ' ' && (arg[i] < '1' || arg[i] > numbers_amount + '0'))
			return (0);
		if ((arg[i] >= '1' && arg[i] <= numbers_amount + '0')
			&& (arg[i + 1] != ' ' && arg[i + 1] != '\0'))
			return (0);
		i++;
	}
	if (arg[i - 1] == ' ')
	{
		return (0);
	}
	return (1);
}
