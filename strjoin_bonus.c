/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strjoin_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/14 17:04:48 by egomez-g          #+#    #+#             */
/*   Updated: 2023/12/19 13:02:02 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	sol_len;
	char	*sol;
	size_t	i;
	size_t	j;

	if (!s2)
		return (NULL);
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
		sol[i] = s2[j++];
		i++;
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
