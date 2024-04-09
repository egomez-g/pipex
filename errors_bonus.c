/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:12 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:44:38 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	errors(int num)
{
	if (OPEN_INFILE == num)
		perror("Error, couldnt open the infile");
	else if (OPEN_OUTFILE == num)
		perror("Error, couldnt create the outfile");
	else if (FAILED_PIPE == num)
		perror("Error, couldnt create the pipe");
	else if (FORK == num)
		perror("Error, couldnt do the fork");
	else if (PATH == num)
	{
		perror("Error, command not found");
		exit (127);
	}
	else if (ENVP == num)
		perror("Error, there is no envp xd?");
	else if (MALLOC == num)
		perror("Error, malloc failed");
	else if (CMD == num)
		perror("Error");
	else if (ARGS == num)
		perror("Error, invalid arguments");
	exit (1);
}
