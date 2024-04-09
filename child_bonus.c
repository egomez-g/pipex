/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/10 16:54:17 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:27:49 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	first_child(int **conect, char **cmd, t_pipex main_args, int here)
{
	char	*real_path;

	if (here == 0)
	{
		conect[0][0] = open(main_args.argv[1], O_RDONLY);
		if (conect[0][0] < 0)
			errors(OPEN_INFILE);
	}
	close(conect[1][0]);
	dup2(conect[1][1], 1);
	close(conect[1][1]);
	dup2(conect[0][0], 0);
	close(conect[0][0]);
	real_path = get_path(main_args.envp, cmd[0]);
	execve(real_path, cmd, main_args.envp);
	exit(127);
}

void	middle_child(int **conect, char **cmd, char **envp)
{
	char	*real_path;

	close(conect[1][1]);
	close(conect[2][0]);
	dup2(conect[2][1], 1);
	close(conect[2][1]);
	dup2(conect[1][0], 0);
	close(conect[1][0]);
	real_path = get_path(envp, cmd[0]);
	execve(real_path, cmd, envp);
	exit(127);
}

void	last_child(int **conect, char **cmd, t_pipex main_args, int here)
{
	char	*real_path;
	char	*name_outfile;

	name_outfile = main_args.argv[main_args.argc - 1];
	if (here == 0)
		conect[0][1] = open(name_outfile, O_CREAT | O_TRUNC | O_RDWR, 0644);
	else
		conect[0][1] = open(name_outfile, O_CREAT | O_APPEND | O_RDWR, 0644);
	if (conect[0][1] < 0)
		errors(OPEN_OUTFILE);
	if (main_args.argc - here != 5)
	{
		close(conect[1][0]);
		close(conect[1][1]);
	}
	dup2(conect[2][0], 0);
	close(conect[2][0]);
	dup2(conect[0][1], 1);
	close(conect[0][1]);
	close(conect[2][1]);
	real_path = get_path(main_args.envp, cmd[0]);
	execve(real_path, cmd, main_args.envp);
	exit(127);
}
