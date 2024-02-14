/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:17:44 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/14 18:47:11 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_heredoc(t_vars *vars, char **argv)
{
	char *tab;
	char *limiter;
	
	limiter = argv[2];	
	tab = malloc(sizeof(char *) + 1);
	if(!tab)
		return ;
	vars->hd_w = open("TMP_HEREDOC", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->hd_w == -1)
	{
		perror("Error opening files");
		exit(1);
	}
		int	count;

		count = 0;
	while(ft_strncmp(tab, limiter, ft_strlen(limiter)))
	{
		write(1, "> ", 1);
		free(tab);
		tab = get_next_line(STDIN_FILENO);
		count++;
		if (!tab)
		{
			ft_putstr_fd("Error\n No limiter for heredoc", 2);
			exit(1);
		}
		ft_putstr_fd(tab, vars->hd_w);
	}
	free(tab);
	close(vars->hd_w);
	vars->fd_infile = open("TMP_HEREDOC", O_RDONLY, 0644);
	if (!vars->hd_r)
	{
		perror("Error opening files");
		unlink("TMP_HEREDOC");
		exit(1);
	}
}
