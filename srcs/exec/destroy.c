/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 22:58:11 by ldurieux          #+#    #+#             */
/*   Updated: 2022/12/13 22:58:12 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_internal.h"

static void	free_exec_cmd(void *ptr)
{
	size_t		idx;
	t_exec_cmd	*cmd;

	cmd = ptr;
	if (!cmd)
		return ;
	free(cmd->name);
	if (cmd->args)
	{
		idx = (size_t) - 1;
		while (cmd->args[++idx])
			free(cmd->args[idx]);
		free(cmd->args);
	}
	free(cmd->here_doc);
	free(cmd);
}

void	exec_destroy(t_exec *exec)
{
	if (!exec)
		return ;
	if (exec->cmds)
	{
		ft_frwlist_iter(exec->cmds, free_exec_cmd);
		ft_frwlist_delete(exec->cmds);
	}
	free(exec->paths);
	free(exec->buffer_out);
	exec->buffer_fd = -1;
}

void	clean(t_exec *exec)
{
	if (exec->cmds)
	{
		ft_frwlist_iter(exec->cmds, free_exec_cmd);
		ft_frwlist_delete(exec->cmds);
		exec->cmds = ft_frwlist_new();
	}
	free(exec->paths);
	exec->paths = NULL;
	exec->envp = NULL;
	exec->flags = Exec_None;
	exec->buffer_fd = -1;
}
