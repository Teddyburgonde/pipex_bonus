/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tebandam <tebandam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 16:11:36 by tebandam          #+#    #+#             */
/*   Updated: 2024/02/11 20:42:56 by tebandam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	check_infile(char **argv, t_vars *vars)
{
	if (access(argv[1], F_OK) != 0 || access(argv[1], R_OK) != 0
		|| access(argv[1], W_OK) != 0)
	{
		ft_putstr_fd("Error\nPermission denied\n", 2);
		exit(1);
	}
	if (!vars->infile)
	{
		ft_putstr_fd("Error\nPermission denied\n", 2);
		exit(1);
	}
}


void	open_files(int argc, t_vars *vars, char **argv)
{
	vars->fd_infile = open(argv[1], O_RDONLY);
	vars->fd_outfile = open(argv[argc -1 ], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (vars->fd_infile == -1 || vars->fd_outfile == -1)
	{
		perror("Error opening files");
		exit(1);
	}
}

void	child_process(t_vars *vars, char *envp[], int actual_cmd)
{
	if (actual_cmd == 0){
		dup2(vars->fd_infile, STDIN_FILENO);
		dup2(vars->pipe[actual_cmd][1], STDOUT_FILENO);
	}
	else if (actual_cmd == vars->nb_cmd - 1){
		dup2(vars->pipe[actual_cmd - 1][0], STDIN_FILENO);
		dup2(vars->fd_outfile, STDOUT_FILENO);
	}
	else{
		dup2(vars->pipe[actual_cmd - 1][0], STDIN_FILENO);
		dup2(vars->pipe[actual_cmd][1], STDOUT_FILENO);
	}

	for (int i = 0; i < vars->nb_cmd - 1; i++)
	{
		close(vars->pipe[i][0]);
		close(vars->pipe[i][1]);
	}
	close(vars->fd_infile);
	close(vars->fd_outfile);
	execve(vars->cmd[actual_cmd][0], vars->cmd[actual_cmd], envp);
	perror("Execve");
	//free si execve foire
	exit(1);
}


int	main(int argc, char **argv, char *envp[])
{
	t_vars	vars;
	if (!envp || !envp[0])
		exit(1);

	// if (argc != 5)
	// {
	// 	ft_putstr_fd("Error\n./pipex infile cmd1 cmd2 outfile\n", 2);
	// 	exit(1);
	// }


	// check_infile(argv, &vars);	

	open_files(argc ,&vars, argv);
	
	vars.nb_cmd = argc -3	;
	vars.path = grep_path(envp);
	if (vars.path == NULL)
	{
		//close les fd 
		exit(1);
	}

	int i = 2;

	vars.cmd = ft_calloc(vars.nb_cmd, sizeof(char **));
	while  (i < vars.nb_cmd + 2 ){
		vars.cmd[i - 2]  = find_the_accessible_path(vars.path, argv[i]);
		if (vars.cmd[i - 2] == NULL){
			//free de 2 a i vars.cmd
			exit(1);
		}
		i++;
	}

	vars.pipe = ft_calloc(vars.nb_cmd, sizeof(int *));

	for (int j = 0; j < vars.nb_cmd - 1; j++){
		vars.pipe[j] = ft_calloc(2, sizeof(int));
		if (pipe(vars.pipe[j]) == -1){
			perror("pipe");
			exit(EXIT_FAILURE);
		}
	}

	i = 0;
	while (i < vars.nb_cmd){

		pid_t child = fork();
		if (child == 0)
		{
			child_process(&vars, envp, i);
		}
		else if (child < 0){
			perror("fork");
			exit(EXIT_FAILURE);
		}

		i++;
	}
	for (int i = 0; i < vars.nb_cmd - 1; i++)
	{
		close(vars.pipe[i][0]);
		close(vars.pipe[i][1]);
	}
	close(vars.fd_infile);
	close(vars.fd_outfile);
	
	while (waitpid(-1, NULL, 0) != -1)
		continue;
	
	// ft_full_free(&vars);
}