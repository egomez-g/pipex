/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:52:09 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:43:31 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*joiner(char **path, t_pipex pipex)
{
	char	*aux;
	char	*sub_path;
	int		i;

	if (!pipex.cmd[0])
		errors (CMD);
	i = 0;
	if (ft_strncmp(pipex.cmd[0], "/", 1) == 0
		|| ft_strncmp(pipex.cmd[0], "./", 2) == 0
		||ft_strncmp(pipex.cmd[0], "../", 3) == 0)
		return (pipex.cmd[0]);
	while (path[i])
	{
		aux = ft_strjoin(path[i], "/");
		sub_path = ft_strjoin(aux, pipex.cmd[0]);
		free(aux);
		if (access(sub_path, F_OK) == 0)
			return (sub_path);
		free(sub_path);
		i++;
	}
	return (path[i]);
}

void	child_process(t_pipex pipex)
{
	char	**path;
	int		i;

	i = 0;
	pipex.infile = open(pipex.argv[1], O_RDONLY);
	if (pipex.infile < 0)
		errors(OPEN_INFILE);
	close (pipex.tube[0]);
	dup2 (pipex.tube[1], 1);
	close (pipex.tube[1]);
	dup2 (pipex.infile, 0);
	close (pipex.infile);
	pipex.cmd = ft_split(pipex.argv[2], ' ');
	if (!pipex.envp)
		errors(PATH);
	while (pipex.envp[i] && ft_strncmp(pipex.envp[i], "PATH=", 5) != 0)
		i++;
	if (!pipex.envp[i])
		errors(PATH);
	path = ft_split(pipex.envp[i] + 5, ':');
	pipex.path = joiner(path, pipex);
	if (!pipex.path)
		errors(PATH);
	execve(pipex.path, pipex.cmd, pipex.envp);
	exit(127);
}

void	parent_process(t_pipex pipex)
{
	char	**p_path;
	int		i;

	i = 0;
	pipex.outfile = open(pipex.argv[4], O_CREAT | O_TRUNC | O_RDWR, 0644);
	if (pipex.outfile < 0)
		errors(OPEN_OUTFILE);
	close (pipex.tube[1]);
	dup2 (pipex.tube[0], 0);
	close (pipex.tube[0]);
	dup2 (pipex.outfile, 1);
	close (pipex.outfile);
	pipex.cmd = ft_split(pipex.argv[3], ' ');
	if (!pipex.envp)
		errors(PATH);
	while (pipex.envp[i] && ft_strncmp(pipex.envp[i], "PATH=", 5) != 0)
		i++;
	if (!pipex.envp[i])
		errors(PATH);
	p_path = ft_split(pipex.envp[i] + 5, ':');
	pipex.path = joiner(p_path, pipex);
	if (!pipex.path)
		errors(PATH);
	execve(pipex.path, pipex.cmd, pipex.envp);
	exit(127);
}

int	main(int argc, char **argv, char **envp)
{
	t_pipex	pipex;
	int		status;

	status = 0;
	if (argc != 5)
		errors (ARGS);
	pipex.envp = envp;
	pipex.argv = argv;
	if (pipe(pipex.tube) < 0)
		errors(FAILED_PIPE);
	pipex.child[0] = fork();
	if (pipex.child[0] < 0)
		errors(FORK);
	if (pipex.child[0] == 0)
		child_process(pipex);
	pipex.child[1] = fork();
	if (pipex.child[1] == 0)
		parent_process(pipex);
	close (pipex.tube[0]);
	close (pipex.tube[1]);
	waitpid(pipex.child[0], NULL, 0);
	waitpid(pipex.child[1], &status, 0);
	return (WEXITSTATUS(status));
}
