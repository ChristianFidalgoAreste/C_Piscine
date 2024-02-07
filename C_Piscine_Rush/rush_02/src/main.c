/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:26:02 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/04 21:26:05 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../deps/memory_to_be_freed.h"

#ifndef DEFAULT_DICT
# define DEFAULT_DICT "resources/numbers.dict"
#endif

int			read_value(char *dict_route, char *value);
int			error(void);

int	main(int argc, char **argv)
{
	// struct s_memory_to_be_freed mem_to_free;
	if (argc < 2 || argc > 3)
		return (error());
	else if (argc == 2)
		return (read_value(DEFAULT_DICT, argv[1]));
	else
		return (read_value(argv[1], argv[2]));
}
