/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_pipex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 12:31:28 by egomez-g          #+#    #+#             */
/*   Updated: 2023/12/15 17:39:43 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*free_all(char **file)
{
	free(*file);
	*file = NULL;
	return (NULL);
}

size_t	ft_strlen(char *s)
{
	size_t	sol;

	sol = 0;
	if (!s)
		return (0);
	while (*(s + sol) != '\0')
		sol++;
	return (sol);
}

char	*ft_strchr(char *s, int c)
{
	int		i;
	char	a;
	char	*sol;

	i = 0;
	sol = (char *)s;
	a = (char) c;
	if (!s)
		return (NULL);
	while (*(s + i))
	{
		if (*(sol + i) == a)
			return (sol + i);
		i++;
	}
	if (a == sol[i])
		return (sol + i);
	return (0);
}

char	*ft_strdup(char *s1)
{
	char	*sol;
	size_t	i;

	sol = malloc((ft_strlen(s1) + 1) * sizeof(const char));
	if (sol == NULL)
		return (sol);
	i = 0;
	while (i < ft_strlen(s1))
	{
		sol[i] = s1[i];
		i++;
	}
	sol[i] = '\0';
	return (sol);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	size_t	i;
	char	*sol;
	size_t	tam;

	if (!s)
		return (NULL);
	tam = ft_strlen(s);
	if (start > tam)
		return (ft_strdup(""));
	if (len > tam - start)
		len = tam - start;
	sol = malloc ((len + 1) * sizeof(char));
	if (sol == NULL)
		return (sol);
	i = 0;
	while (i < len && s[start + i])
	{
		sol[i] = s[start + i];
		i++;
	}
	sol[i] = '\0';
	return (sol);
}
