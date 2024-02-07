/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   generic_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:25:41 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/04 21:25:46 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "../deps/memory_to_be_freed.h"

/*void	free_int_array(int *arr)
{
	if (arr)
		free(arr);
}

void	free_str_array(char **arr)
{
	long	i;

	if (arr)
	{
		i = 0;
		while (i < g_mem_to_free.size)
		{
			if (arr[i])
				free(arr[i]);
			i++;
		}
		free(arr);
		write(1, "str", 3);
	}
}
*/
void	free_memory(void)
{
	/*free_int_array(g_mem_to_free.key_array);
	free_int_array(g_mem_to_free.lengths_tab);
	free_str_array(g_mem_to_free.value_array);
	free_str_array(g_mem_to_free.lines_tab);*/
}

int	error(void)
{
	free_memory();
	write(2, "Error\n", 6);
	return (1);
}

int	dict_error(void)
{
	free_memory();
	write(2, "Dict Error\n", 11);
	return (1);
}
