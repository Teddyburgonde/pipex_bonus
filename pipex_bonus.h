/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:50 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/11 20:28:54 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H 

#define PIPEX_BONUS_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
#include <fcntl.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef struct s_vars{
	char	*infile;
	char	*outfile;
	int		fd_infile;
	int		fd_outfile;
	int		nbr_ac;
	int		heredoc;
	int		nbr_pipes;
	int 	nb_cmd;
	char	**path;
	char	***cmd;
	int		**pipe;

}	t_vars;

char	**grep_path(char **envp);

// void	ft_herodoc(t_vars *vars, char **argv);
void	open_infile(t_vars *vars, char **argv);
void	open_outfile(t_vars *vars, char **argv);
// int		flag_here_doc(char *argv);
char	**find_the_accessible_path(char **path, char *command);

#endif