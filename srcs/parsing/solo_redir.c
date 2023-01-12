/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solo_redir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldurieux <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 15:04:38 by ldurieux          #+#    #+#             */
/*   Updated: 2023/01/12 15:04:40 by ldurieux         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"
#include "input.h"

static char	*get_path(char *str)
{
	while (*str == '>' || *str == '<')
		str++;
	while (ft_is_whitespace(*str))
		str++;
	return (str);
}

static int	add_redir(char *str, char *path)
{
	int	fd;

	fd = -1;
	if (ft_strncmp(str, ">>", 2) == 0)
		fd = open(path, O_WRONLY | O_CREAT | O_APPEND, 0644);
	else if (ft_strncmp(str, "<<", 2) == 0)
	{
		free(here_doc(path, "> "));
		return (1);
	}
	else if (ft_strncmp(str, ">", 1) == 0)
		fd = open(path, O_WRONLY | O_CREAT, 0644);
	else if (ft_strncmp(str, "<", 1) == 0)
		fd = open(path, O_RDONLY);
	if (fd != -1)
		close(fd);
	return (fd != -1);
}

int	solo_redir(t_ftfrwlist *list)
{
	char				*path;
	t_ftfrwlist_node	*node;

	node = list->first;
	while (node)
	{
		path = get_path(node->value);
		if (!add_redir(node->value, path))
		{
			ft_dprintf(2, "%s: %s: %s\n", NAME, path, strerror(errno));
			return (0);
		}
		node = node->next;
	}
	return (1);
}
