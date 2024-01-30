/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/24 16:15:43 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	int		status;
	int		idx;
	int		last_exit_code;

	if (argc != 5)
		exit(EXIT_FAILURE);
	init(argc, argv, envp, &info);
	infile_process(&info, envp);
	outfile_process(&info, envp);
	idx = 0;
	while (idx < info.cmds_len)
	{
		pid = wait(&status);
		if (pid == info.child)
			last_exit_code = WEXITSTATUS(status);
		idx++;
	}
	exit(last_exit_code);
}
