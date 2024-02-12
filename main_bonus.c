/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/12 14:52:32 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;
	int		i;

	i = 2;
	ft_parsing(argc, envp);
	check_infile(argv);
	open_files(argc, &vars, argv);
	vars.nb_cmd = argc -3;
	vars.path = grep_path(envp);
	vars.cmd = ft_calloc(vars.nb_cmd, sizeof(char **));
	fill_command_paths(&vars, argv);
	vars.tmp_fd = -1;
	i = 0;
	fork_processes(&vars, envp);
	close(vars.tmp_fd);
	close(vars.fd_infile);
	close(vars.fd_outfile);
	while (waitpid(-1, NULL, 0) != -1)
		;
	// ft_full_free(&vars);
}
