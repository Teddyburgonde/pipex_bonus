/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_and_close.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/17 14:52:54 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/20 14:22:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **tab)
{
	char	**tmp;

	tmp = tab;
	if (!tab)
		return ;
	while (*tmp)
		free(*(tmp++));
	free(tab);
}

void	ft_free_tab_3d(t_vars *vars)
{
	int	i;
	int	j;

	i = 0;
	if (!vars->cmd)
		return;
	while (vars->cmd[i])
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
