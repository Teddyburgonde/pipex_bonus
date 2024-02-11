/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/10 14:47:44 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/11 17:42:09 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

// void	open_infile(t_vars *vars, char **argv)
// {
// 	vars->infile = open(argv[1], O_RDONLY);
// 	if (!vars->infile)
// 	{
// 		ft_pustr_fd("Error opening file\n");
// 		exit(1);
// 	}
// }
// void	open_outfile(t_vars *vars, char **argv)
// {
// 	vars->outfile = open(argv, O_WRONLY, O_CREAT, O_TRUNC, 0644);
// 	if (!vars->outfile)
// 	{
// 		ft_pustr_fd("Error opening file\n");
// 		exit(1);
// 	}
// }