/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c		                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 18:48:45 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/07 18:49:04 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/map.h"

void	read_from_input(t_maps *maps);
void	use_args(t_maps *maps, char **argv);
void	init_maps(int size, t_maps *maps);
void	calculate_solutions(t_maps *maps);

int	main(int argc, char **argv)
{
	t_maps	maps;

	init_maps(argc - 1, &maps);
	if (argc > 1)
		use_args(&maps, argv);
	else
		read_from_input(&maps);
	return (0);
}
