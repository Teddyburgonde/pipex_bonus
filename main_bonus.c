/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/09 19:04:26 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_herodoc(t_vars *vars)
{
	char *tab;
	char *limiter;
	
	tab = malloc(sizeof(char *) + 1);
	if(!tab)
		return (NULL);
	vars->fd_file = open("heredoc.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->fd_file == -1)
	{
		perror("Error opening files");
		exit(1);
	}
	while(tab != limiter)
	{
		write(1, "> ", 1);
		tab = get_next_line(STDOUT_FILENO);
		ft_putstr_fd(tab, vars->fd_file);
		ft_strncmp(tab, limiter, ft_strlen(limiter));
		free(tab);
	}
	dup2(vars->pipe[1], vars->fd_file);
	close(vars->pipe[1]);
	close(vars->pipe[0]);
		
	
	
	
	dup2(vars->outfile, vars->pipe[1]);
	
	
}
