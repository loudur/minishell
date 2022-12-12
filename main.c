/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <ldurieux@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 22:13:18 by ldurieux          #+#    #+#             */
/*   Updated: 2022/12/09 22:13:20 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "exec.h"

int	main(void)
{
	t_exec exec;

	exec_init(&exec, ft_strdup("/usr/bin"));
	for (int i = 0; i < 2; i++)
		exec_add_cmd(&exec, ft_strdup("/usr/bin/ls"), NULL);
	exec_run(&exec);
	exec_destroy(&exec);

	return (0);
}
