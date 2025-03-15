/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esperance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:29:43 by ilyas             #+#    #+#             */
/*   Updated: 2025/03/15 12:59:03 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ESPERANCE_H
# define ESPERANCE_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
# include <signal.h>

typedef struct s_keys
{
	long int	*keys;
}				t_keys;

typedef struct s_wallet
{
	long int	public_key;
	char		*private_key;
	double		reserve;
	int			fd[3];
	t_keys		own_keys;
}				t_wallet;

// esperance

// ft_encryptage
void			create_keys(t_keys *keys);
void			fill_keys(t_keys *keys);

// wallets
void			create_public_key(t_wallet *wallet);
void			create_wallet(t_wallet *wallet);
void			free_esp(t_wallet *wallet, int exit_fd);

#endif