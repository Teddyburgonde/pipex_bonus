/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:52:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/18 03:24:51 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **tab)
{
	int	i;

	i = 0;
	while (tab && tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_tab_3d(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->nb_cmd)
	{
		j = 0;
		while (vars->cmd[i][j])
		{
			free(vars->cmd[i][j]);
			j++;
		}
		free(vars->cmd[i]);
		i++;
	}
	free(vars->cmd);
}

void	ft_close_fd(t_vars *vars)
{
	close(vars->tmp_fd);
	close(vars->fd_infile);
	close(vars->fd_outfile);
}
