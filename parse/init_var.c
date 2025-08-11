/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chdoe <chdoe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/11 13:50:58 by chdoe             #+#    #+#             */
/*   Updated: 2025/08/11 14:29:04 by chdoe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	init_inout(t_inout_ope *inout)
{
	inout->is_file = false;
	inout->is_cmd = false;
}

void	init_quotes(t_quotes *quotes)
{
	quotes->open_d_quote = false;
	quotes->open_s_quote = false;
	quotes->odd_s_quote = false;
	quotes->odd_d_quote = false;
}