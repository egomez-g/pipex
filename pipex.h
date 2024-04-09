/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:07:58 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:42:34 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

enum
{
	OPEN_INFILE = 0,
	OPEN_OUTFILE = 1,
	FAILED_PIPE = 2,
	FORK = 3,
	PATH = 4,
	ARGS = 5,
	CMD = 6,
};

typedef struct s_pipex
{
	int		infile;
	int		outfile;
	char	*path;
	char	**cmd;
	int		tube[2];
	char	**envp;
	char	**argv;
	pid_t	child[2];
}				t_pipex;

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char const *s1, char const *s2);

void	errors(int num);

#endif