/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+        
	+:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+      
	+#+        */
/*                                                +#+#+#+#+#+  
	+#+           */
/*   Created: 2025/04/04 16:49:47 by nsantand          #+#    #+#             */
/*   Updated: 2025/04/04 16:49:47 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*find_cmd(char **str, char *cmd)
{
	int		i;
	char	*dir_cmd;
	char	**aux;

	i = 0;
	if (cmd[0] == '\0')
		return (NULL);
	if (!aux_find_path(cmd))
		return (NULL);
	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	aux = ft_split(cmd, ' ');
	if (aux == NULL || aux[0] == NULL || aux[0][0] == '\0')
		return (free_array(aux), exit(0), NULL);
	while (str[i] != NULL)
	{
		dir_cmd = ft_strjoinchar(str[i], aux[0], "/");
		if (access(dir_cmd, X_OK) == 0)
			return (free_array(aux), dir_cmd);
		free(dir_cmd);
		i++;
	}
	aux_message(aux[0], 1);
	free_array(aux);
	return (NULL);
}

void	*create_child(char *str, char **envp, char **argv, t_pipex *pipex)
{
	pid_t	pid;
	pid_t	pid2;
	char	**path;

	path = ft_split(ft_strnstr(str, "PATH=", 5) + 5, ':');
	pid = fork();
	if (pid == -1)
		return (perror("Error"), NULL);
	if (pid == 0)
		aux_create_child(path, pipex, argv, envp);
	pid2 = fork();
	if (pid2 == -1)
		return (perror("Error"), NULL);
	if (pid2 == 0)
		aux_create_child2(path, pipex, argv, envp);
	close(pipex->pd[0]);
	close(pipex->pd[1]);
	waitpid(pid, &pipex->status1, 0);
	waitpid(pid2, &pipex->status2, 0);
	free_array(path);
	return ((void *)1);
}

void	*find_path(char *str, char **envp, char **argv, t_pipex *pipex)
{
	if (!create_child(str, envp, argv, pipex))
		return (exit(127), NULL);
	return ((void *)1);
}

void	*initiate_pipex(char **argv, char **envp, t_pipex *pipex)
{
	int	i;

	i = 0;
	while (envp[i] != NULL)
	{
		if (ft_strnstr(envp[i], "PATH=", 5) != NULL)
		{
			if (!find_path(envp[i], envp, argv, pipex))
				return (NULL);
			break ;
		}
		i++;
	}
	return ((void *)1);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		exit_code;

	pipex.status1 = 0;
	pipex.status2 = 0;
	if (argc == 5)
	{
		if (pipe(pipex.pd) == -1)
			return (perror("Error"), EXIT_FAILURE);
		if (!initiate_pipex(argv, envp, &pipex))
			exit(EXIT_FAILURE);
		exit_code = WEXITSTATUS(pipex.status1);
		exit_code = WEXITSTATUS(pipex.status2);
		return (exit_code);
	}
	ft_putendl_fd("Error: Arguments", 2);
	return (EXIT_FAILURE);
}
