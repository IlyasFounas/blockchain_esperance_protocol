/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wallets.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/15 11:38:15 by ilyas             #+#    #+#             */
/*   Updated: 2025/03/15 22:02:19 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "esperance.h"

void	free_esp(t_wallet *wallet, int exit_fd)
{
	if (wallet->own_keys.keys)
		free(wallet->own_keys.keys);
	if (wallet->private_key)
		free(wallet->private_key);
    if (wallet->fd[0])
        close(wallet->fd[0]);
    if (wallet->fd[1])
        close(wallet->fd[1]);
    if (wallet->fd[2])
        close(wallet->fd[2]);
    exit(exit_fd);
}

void	create_private_key(t_wallet *wallet)
{
	int	i;
	int	r;

	i = -1;
	wallet->private_key = malloc(37 + sizeof(char));
	if (!wallet->private_key)
	{
		ft_putstr_fd("private key generation failed\ncheck your RAM please", 2);
		free_esp(wallet, 1);
	}
	while (++i < 36)
	{
		r = rand();
		wallet->private_key[i] = (r % 10) + 48;
	}
	wallet->private_key[i] = '\0';
}

void	create_public_key(t_wallet *wallet)
{
	int	i;
	int	r;

	i = -1;
	wallet->public_key = 0;
	while (++i < 18)
	{
		r = rand();
		wallet->public_key = (wallet->public_key * 10) + r % 10;
	}
}

void	create_wallet(t_wallet *wallet)
{
	wallet->reserve = 0;
	create_public_key(wallet);
	create_private_key(wallet);
	write_fds(wallet);
    ft_printf("This is your private key\nDo not share with anyone : ");
    ft_printf("\n%s\n", wallet->private_key);
}
