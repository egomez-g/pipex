/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 11:12:45 by egomez-g          #+#    #+#             */
/*   Updated: 2023/12/15 17:39:51 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static char	*join(char *s1, char *s2)
{
	size_t	sol_len;
	char	*sol;
	size_t	i;
	size_t	j;

	if (!s1)
		s1 = (ft_strdup(""));
	sol_len = ft_strlen(s1) + ft_strlen(s2);
	sol = malloc ((sol_len + 1) * sizeof(char));
	if (sol == NULL)
		return (free_all(&s1));
	i = 0;
	while (*(s1 + i))
	{
		sol[i] = s1[i];
		i++;
	}
	j = 0;
	while (*(s2 + j))
		sol[i++] = s2[j++];
	sol[i] = '\0';
	free(s1);
	return (sol);
}

static char	*new_file(char *file)
{
	char	*ptr;
	size_t	len;

	ptr = ft_strchr(file, '\n');
	if (!ptr)
		return (free_all(&file));
	len = ptr - file + 1;
	if (!file[len])
		return (free_all(&file));
	ptr = ft_substr(file, len, ft_strlen(file) - len);
	free_all(&file);
	if (!ptr)
		return (NULL);
	return (ptr);
}

static char	*get_line(char *file)
{
	char	*line;
	size_t	len;

	line = ft_strchr(file, '\n');
	if (!line)
		len = ft_strlen(file);
	else
		len = line - file + 1;
	line = ft_substr(file, 0, len);
	if (!line)
		return (NULL);
	return (line);
}

static char	*read_file(int fd, char *file)
{
	int		bytes_read;
	char	*buffer;

	bytes_read = 1;
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (free_all(&file));
	buffer[0] = '\0';
	while (bytes_read > 0 && !ft_strchr(file, '\n'))
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read > 0)
		{
			buffer[bytes_read] = '\0';
			file = join(file, buffer);
		}
	}
	free (buffer);
	if (bytes_read == -1)
		return (free_all(&file));
	return (file);
}

char	*get_next_line(int fd)
{
	static char	*file;
	char		*line;

	if (fd < 0)
		return (NULL);
	if (!file || !ft_strchr(file, '\n'))
		file = read_file(fd, file);
	if (!file)
		return (NULL);
	line = get_line(file);
	if (!line)
		return (free_all(&file));
	file = new_file(file);
	return (line);
}
/*
int main(void)
{
	char *xd;
	int fd = open("archivo.txt", O_RDONLY);
	xd = get_next_line(fd);
	//printf("%s", xd);
	while (xd != NULL)
	{
		xd = get_next_line(fd);
		//printf("%s\n", xd);
		free (xd);
	}
	close (fd);
	return (0);
}*/
