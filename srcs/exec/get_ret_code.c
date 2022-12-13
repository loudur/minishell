/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_child_ret_code.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 22:58:21 by ldurieux          #+#    #+#             */
/*   Updated: 2022/12/12 22:58:23 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"
#include "exec_internal.h"

int	get_child_ret_code(pid_t child_pid)
{
	int	ret_code;

	waitpid(child_pid, &ret_code, 0);
	ret_code = WEXITSTATUS(ret_code);
	return (ret_code);
}

int	get_pipe_ret_code(pid_t *pids, size_t count)
{
	int		ret_code;
	size_t	idx;

	ret_code = ERROR_CODE;
	idx = (size_t)-1;
	while (++idx < count)
		ret_code = get_child_ret_code(pids[idx]);
	free(pids);
	return (ret_code);
}