/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esperance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:35:04 by ilyas             #+#    #+#             */
/*   Updated: 2025/03/15 13:03:42 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "esperance.h"

void	open_fds(t_wallet *wallet)
{
	wallet->fd[0] = open("data/keys.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (wallet->fd[0] == -1)
		free_esp(wallet, 1);
	wallet->fd[1] = open("data/transactions.txt", O_CREAT | O_RDWR | O_TRUNC,
			0644);
	if (wallet->fd[1] == -1)
		free_esp(wallet, 1);
	wallet->fd[2] = open("data/wallets.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (wallet->fd[2] == -1)
		free_esp(wallet, 1);
}

void	write_fds(t_wallet *wallet)
{
	int	i;

	i = -1;
	while (++i < 3)
	{
		write(wallet->fd[0], ft_itoa_esp(wallet->own_keys.keys[i]),
			ft_strlen(ft_itoa_esp(wallet->own_keys.keys[i])));
		write(wallet->fd[0], "\n", 1);
	}
	write(wallet->fd[2], "private_key : ", ft_strlen("private_key : "));
	write(wallet->fd[2], wallet->private_key, ft_strlen(wallet->private_key));
	write(wallet->fd[2], " public_key : ", ft_strlen(" public_key : "));
	write(wallet->fd[2], ft_itoa_esp(wallet->public_key),
		ft_strlen(ft_itoa_esp(wallet->public_key)));
	return ;
}

void handle_sigint(int sig)
{
    (void)sig;
    
    printf("\n🚀 Blockchain shutting down gracefully...\n");
    exit(0);
}

int	main(void)
{
	t_wallet	wallet;
	t_keys		keys;

	signal(SIGINT, handle_sigint);
	srand(time(NULL));
	ft_memset(&wallet, 0, sizeof(t_wallet));
	ft_memset(&keys, 0, sizeof(keys));
	create_keys(&wallet.own_keys);
	create_wallet(&wallet);
	open_fds(&wallet);
	write_fds(&wallet);
	while (1)
	{
		printf("esperance_protcol is running... Press Ctrl+C to exit.\n");
		sleep(2);
	}
	return (0);
}
