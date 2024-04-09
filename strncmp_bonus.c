/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strncmp_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 15:51:52 by egomez-g          #+#    #+#             */
/*   Updated: 2023/12/15 17:36:54 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	s1_c;
	unsigned char	s2_c;

	i = 0;
	while ((*(s1 + i) != '\0' || *(s2 + i) != '\0') && i < n)
	{
		s1_c = s1[i];
		s2_c = s2[i];
		if (s1_c > s2_c)
			return (1);
		if (s1_c < s2_c)
			return (-1);
		i++;
	}
	return (0);
}

/*int main(void)
{
	char char1[] = "h ola";
	char char2[] = "hola";
	int num = 50;
	int res;
	res = ft_strncmp (char1, char2, num);
	printf ("%d", res);
	return (0);
}*/
