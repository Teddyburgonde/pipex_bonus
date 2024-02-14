/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:50 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/14 15:30:50 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H 

# define PIPEX_BONUS_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
# include "./libft/includes/get_next_line.h"
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
	int		hd_w;
	int		hd_r;
}	t_vars;

char	**grep_path(char **envp);

void	ft_heredoc(t_vars *vars, char **argv);
int		is_here_doc(char *argv);
char	**find_the_accessible_path(char **path, char *command);
void	open_files(int argc, t_vars *vars, char **argv);
void	check_infile(char **argv);
void	child_process(t_vars *vars, char *envp[], int actual_cmd);
void	fork_processes(t_vars *vars, char *envp[]);
void	ft_parsing(int argc, char *envp[]);
void	fill_command_paths(t_vars *vars, char **argv);

#endif