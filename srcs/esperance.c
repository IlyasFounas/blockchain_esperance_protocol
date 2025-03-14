/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   esperance.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilyas <ilyas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/14 22:35:04 by ilyas             #+#    #+#             */
/*   Updated: 2025/03/14 23:14:24 by ilyas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "esperance.h"

void    create_wallet(t_wallet *wallet, t_keys *keys)
{
    (void)wallet;
    fill_keys(keys);
    if (!keys->keys)
        exit(1);
    printf("%ld\n", keys->keys[0]);
    printf("%ld\n", keys->keys[1]);
    printf("%ld\n", keys->keys[2]);
    wallet->reserve = 100;
}

int main(void)
{
    t_wallet wallet;
    t_keys keys;

    ft_memset(&wallet, 0, sizeof(t_wallet));
    ft_memset(&keys, 0, sizeof(keys));
    create_wallet(&wallet, &keys);
    return (0);
}
