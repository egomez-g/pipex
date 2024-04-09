/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 17:35:29 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:49:29 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	waiting(int argc, int here, int *status)
{
	int	i;

	i = here;
	while (i < argc - 3)
	{
		waitpid(-1, status, 0);
		i++;
	}
}

char	*joiner(char **path, char *cmd)
{
	char	*aux;
	char	*sub_path;
	int		i;

	i = 0;
	while (path[i])
	{
		aux = ft_strjoin(path[i], "/");
		sub_path = ft_strjoin(aux, cmd);
		free(aux);
		if (access(sub_path, F_OK) == 0)
			return (sub_path);
		free(sub_path);
		i++;
	}
	return (NULL);
}

char	*get_path(char **envp, char *cmd)
{
	char	*real_path;
	char	**path;
	int		i;

	i = 0;
	if (!cmd)
		errors(CMD);
	if (ft_strncmp(cmd, "/", 1) == 0 || ft_strncmp(cmd, "./", 2) == 0
		||ft_strncmp(cmd, "../", 3) == 0)
		return (cmd);
	if (!envp)
		errors(ENVP);
	while (envp[i] && ft_strncmp(envp[i], "PATH=", 5) != 0)
		i++;
	if (!envp[i])
		errors(PATH);
	path = ft_split(envp[i] + 5, ':');
	real_path = joiner(path, cmd);
	i = 0;
	while (path[i])
		free (path[i++]);
	free (path);
	if (!real_path)
		errors(PATH);
	return (real_path);
}
