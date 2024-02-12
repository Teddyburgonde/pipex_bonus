/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 15:16:30 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/12 14:56:14 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	flag_here_doc(char *argv)
{
	if (argv && ft_strncmp(argv, "here_doc", 9) == 0)
		return (0);
	return (1);
}

void	ft_parsing(int argc, char *envp[])
{
	if (!envp || !envp[0])
	{
		ft_putstr_fd("Error\nVariables envp\n", 2);
		exit(1);
	}
	if (argc <= 3)
	{
		ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile\n", 2);
		exit(1);
	}
}
