/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   paths_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:29:52 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/18 04:06:24 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**grep_path(char **envp)
{
	char	**tmp;
	int		i;

	i = 0;
	while (envp[i] != NULL && ft_strncmp("PATH", envp[i], 4) != 0)
		i++;
	if (envp[i] != NULL)
	{
		tmp = ft_split(envp[i] + 5, ':');
		return (tmp);
	}
	return (NULL);
}

void	update_full_cmd(char ***full_cmd, char *is_valid_cmd)
{
	free((*full_cmd)[0]);
	(*full_cmd)[0] = NULL;
	(*full_cmd)[0] = malloc(ft_strlen(is_valid_cmd) + 1);
	ft_strlcpy((*full_cmd)[0], is_valid_cmd, ft_strlen(is_valid_cmd) + 1);
	free(is_valid_cmd);
}

char	**find_the_accessible_path(char **path, char *command)
{
	char	**full_cmd;
	int		i;
	int		arr_len;
	char	*bin_path;
	char	*is_valid_cmd;

	i = 0;
	arr_len = 0;
	full_cmd = ft_split(command, ' ');
	if (full_cmd == NULL)
	{
		ft_free(full_cmd);
		return (NULL);
	}
	arr_len = ft_array_len(full_cmd);
	if (access(full_cmd[0], X_OK) == 0)
		return (full_cmd);
	while (path[i])
	{
		bin_path = ft_strjoin(path[i++], "/");
		is_valid_cmd = ft_strjoin(bin_path, full_cmd[0]);
		free(bin_path);
		if (access(is_valid_cmd, X_OK) == 0)
		{
			update_full_cmd(&full_cmd, is_valid_cmd);
			break ;
		}
		free(is_valid_cmd);
	}
	return (full_cmd);
}

void	fill_command_paths(t_vars *vars, char **argv)
{
	int	configuration;
	int	i;

	if (is_here_doc(argv[1]))
		configuration = 3;
	else
		configuration = 2;
	i = configuration;
	while (i < vars->nb_cmd + configuration)
	{
		vars->cmd[i - configuration] = find_the_accessible_path(vars->path, argv[i]);
		if (vars->cmd[i - configuration] == NULL)
		{
			exit(1);
		}
		i++;
	}
}
