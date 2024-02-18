/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:17:44 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/18 02:56:51 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_heredoc(t_vars *vars, char **argv)
{
	char *tmp;
	char *tab;
	int	i;

	i = 0;
	tab = NULL;
	tmp = malloc(sizeof(char) * ft_strlen(argv[2]) + 2);
	while (argv[2][i] != '\0')
	{
		tmp[i] = argv[2][i];
		i++;
	}
	tmp[i] = '\n';
	tmp[i + 1] = '\0';
	vars->hd_w = open("TMP_HEREDOC", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->hd_w == -1)
	{
		perror("Error opening files");
		exit(1);
	}
	write(1, "> ", 2);
	tab = get_next_line(STDIN_FILENO);
	if (!tab)
	{
		ft_putstr_fd("Error\n No limiter for heredoc", 2);
		exit(1);
	}
	while(ft_strncmp(tab, tmp, ft_strlen(tmp)))
	{
		ft_putstr_fd(tab, vars->hd_w);
		free(tab);
		write(1, "> ", 2);
		tab = get_next_line(STDIN_FILENO);
		if (!tab)
		{
			ft_putstr_fd("Error\n No limiter for heredoc", 2);
			exit(1);
		}
	}
	free(tab);
	free(tmp);
	close(vars->hd_w);
	vars->fd_infile = open("TMP_HEREDOC", O_RDONLY, 0644);
	if (!vars->fd_infile)
	{
		perror("Error opening files");
		exit(1);
	}
	unlink("TMP_HEREDOC");
}
