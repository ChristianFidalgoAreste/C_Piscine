/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_vws.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/29 05:08:33 by arcanava          #+#    #+#             */
/*   Updated: 2023/10/29 05:08:35 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_vws(int ibase, int iaug, char *str)
{
	if (str[iaug] == '\0')
		return (0);
	else if (str[iaug] - str[ibase] > 0)
		return (get_vws(ibase + 1, iaug + 1, str) + 1);
	else
		return (get_vws(ibase, iaug + 1, str));
}
