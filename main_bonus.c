/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/10 16:29:42 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"



int	main(int argc, char **argv, char *envp[])
{
	if (flag_here_doc(argv[1]) == 1)
	{
		ft_pustr_fd("Error\nMissing the heredoc");
		exit(1);
	}
	//pipex.cmd_nmbs = argc - 3 - pipex.here_doc;
	//pipex.pipe_nmbs = 2 * (pipex.cmd_nmbs - 1);
}