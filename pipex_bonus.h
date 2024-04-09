/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:07:58 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:49:38 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# define BUFFER_SIZE 42

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <errno.h>

enum e_num
{
	OPEN_INFILE = 0,
	OPEN_OUTFILE = 1,
	FAILED_PIPE = 2,
	FORK = 3,
	PATH = 4,
	ENVP = 5,
	MALLOC = 6,
	CMD = 7,
	ARGS = 8,
}e_numclose;

typedef struct s_pipex
{
	int		argc;
	char	**argv;
	char	**envp;
}	t_pipex;

char	**ft_split(char const *s, char c);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_substr(char *s, unsigned int start, size_t len);
char	*ft_strdup(char *s1);
char	*get_next_line(int fd);
char	*ft_strchr(char *s, int c);
size_t	ft_strlen(char *s);
char	*free_all(char **file);

void	errors(int num);
char	*joiner(char **path, char *cmd);
void	first_child(int **conect, char **cmd, t_pipex main_args, int here);
void	middle_child(int **conect, char **cmd, char **envp);
void	last_child(int **conect, char **cmd, t_pipex main_args, int here);
char	*get_path(char **envp, char *cmd);
int		heredoc(char **argv, int **conect);
void	waiting(int argc, int here, int *status);

#endif