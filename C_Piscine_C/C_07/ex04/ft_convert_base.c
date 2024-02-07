/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfidalgo <cfidalgo@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 14:14:23 by cfidalgo          #+#    #+#             */
/*   Updated: 2023/11/02 20:29:58 by cfidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int	ft_atoi_base(char *nbr, char *base, int negs, int base_length);
int	calculate_neg(char **nbr, char *base_from);

int	calculate_base_length(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i] != '\0')
	{
		j = i + 1;
		while (base[j] != '\0')
			if (base[i] == base[j++])
				return (1);
		if (base[i] == '+' || base[i] == '-' || base[i] < 32 || base[i] >= 127)
			return (1);
		i++;
	}
	return (i);
}

int	change_num_sign(long *nbr, char **raw_num_str)
{
	int	i;

	i = 0;
	if (*nbr < 0)
	{
		*nbr = -(*nbr);
		(*raw_num_str)[0] = '-';
		i++;
	}
	return (i);
}

char	*ft_putnbr_base(long nbr, char *base, int base_length, int j)
{
	char	*raw_num_str;
	char	*prsd_num_str;
	int		i;
	int		is_neg;

	is_neg = j;
	raw_num_str = malloc(32 * sizeof(char));
	if (!raw_num_str)
		return (0);
	i = change_num_sign(&nbr, &raw_num_str);
	while (nbr > 0)
	{
		raw_num_str[i++] = base[nbr % base_length];
		nbr /= base_length;
	}
	prsd_num_str = malloc((i + j) * sizeof(char));
	if (!prsd_num_str)
		return (0);
	if (j == 1)
		prsd_num_str[0] = '-';
	while (--i >= is_neg)
		prsd_num_str[j++] = raw_num_str[i];
	prsd_num_str[j] = '\0';
	free(raw_num_str);
	return (prsd_num_str);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char		*dest_num;
	int			negs;
	int			fr_lgth;
	int			to_lgth;
	long		num_dec;

	negs = calculate_neg(&nbr, base_from);
	printf("anegs: %s\n", nbr);
	fr_lgth = calculate_base_length(base_from);
	to_lgth = calculate_base_length(base_to);
	if (negs == -1 || fr_lgth <= 1 || to_lgth <= 1)
		return (0);
	num_dec = ft_atoi_base(nbr, base_from, negs, fr_lgth);
	printf("num: %ld\n", num_dec);
	dest_num = ft_putnbr_base((long) num_dec, base_to, to_lgth, negs % 2);
	if (!dest_num)
		return (0);
	return (dest_num);
}

int	main(void)
{
	printf("%s", ft_convert_base("---++00000", "0123456789", "0123456789abcdef"));
}
