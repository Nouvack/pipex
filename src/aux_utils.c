/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   aux_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/07 12:11:34 by nsantand          #+#    #+#             */
/*   Updated: 2025/04/08 12:44:16 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*aux_open_files(char **argv, t_pipex *pipex, int i)
{
	if (i == 1)
	{
		pipex->infile = open(argv[1], O_RDONLY);
		if (pipex->infile < 0)
			return (perror("Error"), NULL);
	}
	if (i == 2)
	{
		pipex->outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (pipex->outfile < 0)
			return (perror("Error"), NULL);
	}
	return ((void *) 1);
}

void	aux_message(char *cmd, int i)
{
	char	*str;

	if (i == 1)
	{
		str = ft_strjoin(cmd, ": command not found\n");
		ft_putstr_fd(str, 2);
		free(str);
	}
	else if (i == 2)
	{
		str = ft_strjoin(cmd, ": Permission denied\n");
		ft_putstr_fd(str, 2);
		free(str);
	}
}

void	*aux_find_path(char *cmd)
{
	if (cmd[0] == '\0')
		return (NULL);
	if (cmd == NULL)
		return (aux_message(cmd, 1), NULL);
	if (ft_strnstr(cmd, "./", ft_strlen(cmd)))
	{
		aux_message(cmd, 1);
		return (NULL);
	}
	return ((void *)1);
}
