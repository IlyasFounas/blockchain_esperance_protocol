/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_encryptage.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:41:38 by ilyas             #+#    #+#             */
/*   Updated: 2025/03/15 11:37:51 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "esperance.h"

void	create_keys(t_keys *keys)
{
	fill_keys(keys);
	if (!keys->keys)
	{
		ft_putstr_fd("Error\ncheck your RAM please", 2);
		exit(1);
	}
}

void	fill_keys(t_keys *keys)
{
	int	r;
	int	i;
	int	j;

	i = 0;
	keys->keys = malloc(3 * sizeof(long int));
	if (!keys->keys)
		return ;
	while (i < 3)
	{
		j = 0;
		while (j < 18)
		{
			r = rand();
			keys->keys[i] = (keys->keys[i] * 10) + r % 10;
			j++;
		}
		i++;
	}
}

// void    ft_encryptage(t_keys *keys, t_wallet *wallet)
// {

// }
