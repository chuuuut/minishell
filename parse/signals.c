/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/28 09:32:25 by chdoe             #+#    #+#             */
/*   Updated: 2025/07/29 18:53:25 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void    sh_ctrlc_behave(int signal)
{
    (void)  signal;
    printf("\n");
    rl_on_new_line();           //met le curseur au home
    rl_replace_line("", 0);     //vide le buffer
    rl_redisplay();             //reaffiche le prompt
}

void    get_signal(void)
{
    signal(SIGINT, sh_ctrlc_behave);
    signal(SIGQUIT, SIG_IGN);
}
