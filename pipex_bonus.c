/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 11:52:09 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:49:54 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	free_conect(int **conect)
{
	int	i;

	i = 0;
	while (i < 3)
	{
		free(conect[i]);
		i++;
	}
	free(conect);
}

void	prep_last_child(int **conect, t_pipex main_args, int i, int here)
{
	pid_t	child;

	child = fork();
	if (child < 0)
		errors(FORK);
	if (child == 0)
	{
		if (i - here == 2)
		{
			conect[2][0] = conect[1][0];
			conect[2][1] = conect[1][1];
		}
		last_child(conect, ft_split(main_args.argv[i + 1], ' ') \
		, main_args, here);
	}
	close (conect[1][0]);
	close (conect[1][1]);
	close (conect[2][0]);
	close (conect[2][1]);
	free_conect(conect);
}

int	**inizialite(int **conect, char **argv, int argc, int *here)
{
	conect = malloc (sizeof(int *) * 3);
	if (!conect)
		errors(MALLOC);
	conect[0] = malloc (sizeof(int) * 2);
	if (!conect[0])
		errors(MALLOC);
	conect[1] = malloc (sizeof(int) * 2);
	if (!conect[1])
		errors(MALLOC);
	conect[2] = malloc (sizeof(int) * 2);
	if (!conect[2])
		errors(MALLOC);
	*here = heredoc(argv, conect);
	argc = argc + 1;
	argc = argc - 1;
	if (pipe(conect[1]) < 0)
		errors(FAILED_PIPE);
	return (conect);
}

void	pipex(int **conect, t_pipex main_args, int here)
{
	int		i;
	pid_t	child;

	i = 2 + here;
	while (i < main_args.argc - 3)
	{
		if (i - here > 2)
		{
			close (conect[1][0]);
			close (conect[1][1]);
			conect[1][0] = conect[2][0];
			conect[1][1] = conect[2][1];
		}
		if (pipe(conect[2]) < 0)
			errors(FAILED_PIPE);
		child = fork();
		if (child == 0)
			middle_child(conect, ft_split(main_args.argv[i + 1], ' ') \
			, main_args.envp);
		i++;
	}
	prep_last_child(conect, main_args, i, here);
}

int	main(int argc, char **argv, char **envp)
{
	int		**conect;
	pid_t	child;
	int		here;
	t_pipex	main_args;
	int		status;

	conect = NULL;
	here = 0;
	status = 0;
	main_args.argc = argc;
	main_args.argv = argv;
	main_args.envp = envp;
	if (argc < 5)
		errors (ARGS);
	conect = inizialite(conect, argv, argc, &here);
	child = fork();
	if (child < 0)
		errors(FORK);
	if (child == 0)
		first_child(conect, ft_split(argv[2 + here], ' '), main_args, here);
	pipex(conect, main_args, here);
	unlink(".here_doc");
	waiting(argc, here, &status);
	return (WEXITSTATUS(status));
}
