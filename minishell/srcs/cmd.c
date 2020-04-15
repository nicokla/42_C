/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyhuet <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 09:18:04 by cyhuet            #+#    #+#             */
/*   Updated: 2019/11/25 09:18:06 by cyhuet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_file_cmd(t_cmd *cmd)
{
	if (!(cmd->in = malloc(sizeof(t_rdir))))
		fatal_error(strerror(errno));
	cmd->in->file = NULL;
	if (!(cmd->out = malloc(sizeof(t_rdir))))
		fatal_error(strerror(errno));
	cmd->out->file = NULL;
	if (!(cmd->out_dbl = malloc(sizeof(t_rdir))))
		fatal_error(strerror(errno));
	cmd->out_dbl->file = NULL;
}

void	free_cmd(t_cmd *cmd)
{
	if (cmd->in->file)
		free(cmd->in->file);
	if (cmd->out->file)
		free(cmd->out->file);
	if (cmd->out_dbl->file)
		free(cmd->out_dbl->file);
	free(cmd->in);
	free(cmd->out);
	free(cmd->out_dbl);
	if (cmd->argv)
		free_arr(cmd->argv);
	free(cmd);
}
