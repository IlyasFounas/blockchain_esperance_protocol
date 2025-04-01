/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esperance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:35:04 by ilyas             #+#    #+#             */
/*   Updated: 2025/04/01 22:25:55 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#include "esperance.h"

void	open_fds(t_wallet *wallet)
{
	wallet->fd[0] = open("data/keys.txt", O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (wallet->fd[0] == -1)
		free_esp(wallet, 1);
	wallet->fd[1] = open("data/transactions.txt", O_CREAT | O_RDWR, 0644);
	if (wallet->fd[1] == -1)
		free_esp(wallet, 1);
	// wallet->fd[2] = open("data/wallets.txt", O_CREAT | O_RDWR, 0644);
	// if (wallet->fd[2] == -1)
	// 	free_esp(wallet, 1);
}

void	write_fds(t_wallet *wallet)
{
	wallet->fd[2] = open("data/wallets.txt", O_RDWR | O_APPEND, 0644);
	if (wallet->fd[2] == -1)
		free_esp(wallet, 1);
	write(wallet->fd[2], "\n", 1);
	write(wallet->fd[2], "private_key : ", ft_strlen("private_key : "));
	write(wallet->fd[2], wallet->private_key, ft_strlen(wallet->private_key));
	write(wallet->fd[2], " public_key : ", ft_strlen(" public_key : "));
	write(wallet->fd[2], ft_itoa_esp(wallet->public_key),
		ft_strlen(ft_itoa_esp(wallet->public_key)));
	close(wallet->fd[2]);
	return ;
}

void	handle_sigint(int sig)
{
	(void)sig;
	printf("\n🚀 Blockchain shutting down gracefully...\n");
	exit(0);
}

int	main(void)
{
	t_wallet	wallet;
	t_keys		keys;
	char		*line;

	signal(SIGINT, handle_sigint);
	srand(time(NULL));
	ft_memset(&wallet, 0, sizeof(t_wallet));
	ft_memset(&keys, 0, sizeof(keys));
	open_fds(&wallet);
	create_keys(&wallet);
	while (1)
	{
		line = readline("esp_protocol > ");
		add_history(line);
		if (ft_strncmp("create_wallet\n", line, ft_strlen(line)) == 0)
			create_wallet(&wallet);
		free(line);
	}
	return (0);
}
