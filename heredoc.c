/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 11:17:44 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/11 17:41:02 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	ft_herodoc(t_vars *vars, char **argv)
// {
// 	char *tab;
// 	char *limiter;
	
// 	limiter = argv[2];	
// 	tab = malloc(sizeof(char *) + 1);
// 	if(!tab)
// 		return (NULL);
// 	vars->fd_file_for_write = open("TMP_HEREDOC", O_WRONLY | O_CREAT | O_TRUNC, 0644);
// 	if (vars->fd_file_for_write == -1)
// 	{
// 		perror("Error opening files");
// 		exit(1);
// 	}
// 	while(!ft_strncmp(tab, limiter, ft_strlen(limiter)))
// 	{
// 		write(1, "> ", 1);
// 		free(tab);
// 		tab = get_next_line(STDOUT_FILENO);
// 		ft_putstr_fd(tab, vars->fd_file_for_write);
// 	}
// 	free(tab);
// 	close(vars->fd_file_for_write);
// 	vars->fd_file_for_read = open("TMP_HEREDOC", O_RDONLY);
// 	if (!vars->fd_file_for_read)
// 	{
// 		perror("Error opening files");
// 		unlink("TMP_HEREDOC");
// 		exit(1);
// 	}
// }
