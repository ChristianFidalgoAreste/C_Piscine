/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 15:58:08 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/08 15:58:10 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

typedef struct s_map
{
	int		is_valid;
	char	empty;
	char	obstacle;
	char	full;
	char	**lines;
	int		size;
	int		line_size;
}	t_map;

typedef struct s_maps
{
	t_map	*list;
	int		size;
}	t_maps;
