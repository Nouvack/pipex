/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/04 17:10:37 by nsantand          #+#    #+#             */
/*   Updated: 2025/04/04 17:10:37 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*aux_create_child(char **path, t_pipex *pipex, char **argv, char **envp)
{
	char	**cmd_args;

	if (argv[2][0] == '\0')
		argv[2] = "cat";
	if (!aux_open_files(argv, pipex, 1))
		return (free_array(path), exit(EXIT_FAILURE), NULL);
	pipex->dir_cmd = find_cmd(path, argv[2]);
	if (!pipex->dir_cmd)
		return (dup2(pipex->infile, STDIN_FILENO), dup2(pipex->pd[1],
				STDOUT_FILENO), close(pipex->pd[0]), close(pipex->pd[1]),
			free_array(path), exit(127), NULL);
	cmd_args = child1(pipex, argv);
	if (!cmd_args)
		return (free(pipex->dir_cmd), free_array(path), exit(1), NULL);
	free_array(path);
	if (execve(pipex->dir_cmd, cmd_args, envp) == -1)
		return (perror("Error"), exit(EXIT_FAILURE), NULL);
	return ((void *)1);
}

void	*aux_create_child2(char **path, t_pipex *pipex, char **argv,
			char **envp)
{
	char	**cmd_args2;

	if (argv[3][0] == '\0')
		argv[3] = "cat";
	if (!aux_open_files(argv, pipex, 2))
		return (free_array(path), exit(EXIT_FAILURE), NULL);
	pipex->dir_cmd2 = find_cmd(path, argv[3]);
	if (!pipex->dir_cmd2)
		return (dup2(pipex->pd[0], STDIN_FILENO), dup2(pipex->outfile,
				STDOUT_FILENO), close(pipex->pd[0]), close(pipex->pd[1]),
			free_array(path), exit(127), NULL);
	cmd_args2 = child2(pipex, argv);
	if (!cmd_args2)
		return (free(pipex->dir_cmd2), free_array(path), exit(1), NULL);
	free_array(path);
	if (execve(pipex->dir_cmd2, cmd_args2, envp) == -1)
		return (perror("Error"), exit(EXIT_FAILURE), NULL);
	return ((void *)1);
}

char	**child1(t_pipex *pipex, char **argv)
{
	char	**cmd_args;

	dup2(pipex->infile, STDIN_FILENO);
	dup2(pipex->pd[1], STDOUT_FILENO);
	close(pipex->pd[0]);
	close(pipex->pd[1]);
	cmd_args = ft_split(argv[2], ' ');
	if (!cmd_args)
		return (NULL);
	return (cmd_args);
}

char	**child2(t_pipex *pipex, char **argv)
{
	char	**cmd_args;

	dup2(pipex->pd[0], STDIN_FILENO);
	dup2(pipex->outfile, STDOUT_FILENO);
	close(pipex->pd[0]);
	close(pipex->pd[1]);
	cmd_args = ft_split(argv[3], ' ');
	if (!cmd_args)
		return (NULL);
	return (cmd_args);
}
