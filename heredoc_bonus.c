/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 15:41:22 by egomez-g          #+#    #+#             */
/*   Updated: 2023/12/22 17:46:37 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	heredoc(char **argv, int **conect)
{
	char	*buff;
	int		doc_fd;

	if (ft_strncmp("here_doc", argv[1], 9) != 0)
		return (0);
	doc_fd = open(".here_doc", O_CREAT | O_WRONLY | O_APPEND, 0644);
	if (doc_fd < 0)
		errors(OPEN_INFILE);
	while (1)
	{
		buff = get_next_line(0);
		if (!buff || !ft_strncmp(buff, ft_strjoin(argv[2], "\n") \
		, ft_strlen(buff)))
			break ;
		write(doc_fd, buff, ft_strlen(buff));
		free (buff);
	}
	free(buff);
	close (doc_fd);
	conect[0][0] = open(".here_doc", O_RDONLY);
	return (1);
}
