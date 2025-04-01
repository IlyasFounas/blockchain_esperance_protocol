/******************************************************************************/
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esperance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:29:43 by ilyas             #+#    #+#             */
/*   Updated: 2025/04/01 22:16:02 by marvin           ###   ########.fr       */
/*                                                                            */
/******************************************************************************/

#ifndef ESPERANCE_H
# define ESPERANCE_H

# include "../libft/libft.h"
# include <fcntl.h>
# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <time.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct s_keys
{
	long int	*keys;
}				t_keys;

typedef struct s_wallet
{
	long int	public_key;
	int			fd[3];
	double		reserve;
	char		*private_key;
	t_keys		own_keys;
}				t_wallet;

// esperance
void			write_fds(t_wallet *wallet);

// ft_encryptage
void			create_keys(t_wallet *wallet);
void			fill_keys(t_keys *keys);

// wallets
void			create_public_key(t_wallet *wallet);
void			create_wallet(t_wallet *wallet);
void			free_esp(t_wallet *wallet, int exit_fd);

#endif