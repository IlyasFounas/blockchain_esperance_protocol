/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esperance.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:29:43 by ilyas             #+#    #+#             */
/*   Updated: 2025/03/14 23:04:41 by ilyas            ###   ########.fr       */
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

typedef struct s_wallet
{
	long int	public_key;
	char		*private_key;
	double		reserve;
}				t_wallet;

typedef struct s_keys
{
	long int	*keys;
}				t_keys;

// ft_encryptage
void			fill_keys(t_keys *keys);

#endif