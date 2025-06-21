/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsantand <nsantand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 12:41:25 by nsantand          #+#    #+#             */
/*   Updated: 2025/04/01 12:48:38 by nsantand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "get_next_line.h"
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <fcntl.h>

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	int		pd[2];
	int		status1;
	int		status2;
	char	*dir_cmd;
	char	*dir_cmd2;

}	t_pipex;

void	free_array(char **str);
void	*find_cmd(char **str, char *cmd);
void	*aux_find_path(char *cmd);
void	*create_child(char *str, char **envp, char **argv, t_pipex *pipex);
void	*find_path(char *str, char **envp, char **argv, t_pipex *pipex);
void	*initiate_pipex(char **argv, char **envp, t_pipex *pipex);
void	*aux_create_child(char **path, t_pipex *pipex,
			char **argv, char **envp);
void	*aux_create_child2(char **path, t_pipex *pipex,
			char **argv, char **envp);
char	**child1(t_pipex *pipex, char **argv);
char	**child2(t_pipex *pipex, char **argv);
void	aux_message(char *cmd, int i);
void	*aux_open_files(char **argv, t_pipex *pipex, int i);
#endif