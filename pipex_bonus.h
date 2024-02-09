/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:33:50 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/09 17:38:30 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H 

#define PIPEX_BONUS_H

# include "./libft/includes/libftprintf.h"
# include "./libft/includes/libft.h"
#include <fcntl.h>

typedef struct s_vars{
	int	fd_file;
	int	pipe[2];
	char *outfile;
}	t_vars;


void	ft_herodoc(t_vars *vars);

#endif