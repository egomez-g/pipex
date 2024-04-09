/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:04:48 by egomez-g          #+#    #+#             */
/*   Updated: 2023/12/16 13:20:05 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static size_t	ft_strlen(const char *s)
{
	size_t	sol;

	sol = 0;
	while (*(s + sol) != '\0')
		sol++;
	return (sol);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	sol_len;
	char	*sol;
	size_t	i;
	size_t	j;

	sol_len = ft_strlen(s1) + ft_strlen(s2);
	sol = malloc ((sol_len + 1) * sizeof(char));
	if (sol == NULL)
		return (sol);
	i = 0;
	while (*(s1 + i))
	{
		sol[i] = s1[i];
		i++;
	}
	j = 0;
	while (*(s2 + j))
	{
		sol[i] = s2[j];
		i++;
		j++;
	}
	sol[i] = '\0';
	return (sol);
}
/*int main(void)
{
	char	s1[] = "wow";
	char	s2[] = "ers";
	printf ("%s", ft_strjoin(s1, s2));
	return (0);
}*/
