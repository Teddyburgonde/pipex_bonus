/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:50 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/12 14:54:53 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H 

# define PIPEX_BONUS_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_vars{
	pid_t	child;
	int		fd_infile;
	int		fd_outfile;
	int		nb_cmd;
	int		heredoc;
	char	**path;
	char	***cmd;
	int		pipe_1[2];
	int		tmp_fd;
}	t_vars;

char	**grep_path(char **envp);

// void	ft_herodoc(t_vars *vars, char **argv);
// int		flag_here_doc(char *argv);
char	**find_the_accessible_path(char **path, char *command);
void	open_files(int argc, t_vars *vars, char **argv);
void	check_infile(char **argv);
void	child_process(t_vars *vars, char *envp[], int actual_cmd);
void	fork_processes(t_vars *vars, char *envp[]);
void	ft_parsing(int argc, char *envp[]);
void	fill_command_paths(t_vars *vars, char **argv);

#endif