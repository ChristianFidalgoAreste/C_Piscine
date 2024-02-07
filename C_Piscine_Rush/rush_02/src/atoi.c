/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atoi.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arcanava <arcanava@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 21:24:31 by arcanava          #+#    #+#             */
/*   Updated: 2023/11/04 21:24:34 by arcanava         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long	ft_atoi(char *str)
{
	long	i;
	long	j;
	i = 0;
	j = 0;
	while (str[j] != '\0')
	{
		if ('0' <= str[j] && str[j] <= '9')
		{
			i = i * 10;
			i = i + str[j] - '0';
			j++;
		}
		else
			return (-1);
	}
	return (i);
}