/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_esp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 12:44:50 by ilyas             #+#    #+#             */
/*   Updated: 2025/03/15 12:49:38 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_charnbr(long int n, int size, char *res)
{
	if (n >= 0 && n <= 9)
	{
		size++;
		res[size] = (n + '0');
		res[size + 1] = '\0';
	}
	if (n > 9)
	{
		ft_charnbr(n / 10, size, res);
		ft_charnbr(n % 10, ft_strlen(res) - 1, res);
	}
	return (res);
}

char	*ft_itoa_esp(long int n)
{
	char *res;
	long int i;
	long int n_cpy;

	i = 0;
	if (n == 0)
		i++;
	n_cpy = n;
	while (n_cpy >= 1)
	{
		n_cpy /= 10;
		i++;
	}
	res = malloc((i + 1) * sizeof(char));
	if (res == NULL)
		return (0);
	res = ft_charnbr(n, -1, res);
	return (res);
}