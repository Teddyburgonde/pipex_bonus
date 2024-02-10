/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:50 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/10 15:17:58 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H 

#define PIPEX_BONUS_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
#include <fcntl.h>

typedef struct s_vars{
	int	pipe[2];
	char	*infile;
	char	*outfile;
	int	fd_file_for_read;
	int	fd_file_for_write;
}	t_vars;


void	ft_herodoc(t_vars *vars, char **argv);
void	open_infile(t_vars *vars, char **argv);
void	open_outfile(t_vars *vars, char **argv);
int		flag_here_doc(char *argv);

#endif