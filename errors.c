/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: egomez-g <egomez-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 13:03:12 by egomez-g          #+#    #+#             */
/*   Updated: 2024/02/07 12:39:50 by egomez-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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
	else if (ARGS == num)
		perror("Error, invalid argument");
	else if (CMD == num)
		perror("Error");
	exit (1);
}
