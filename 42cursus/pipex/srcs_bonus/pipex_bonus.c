/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/30 22:49:52 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/pipex_bonus.h"

int	main(int argc, char **argv, char **envp)
{
	t_info	info;
	pid_t	pid;
	int		status;
	int		last_exit_code;

	if (argc < 5)
		exit(EXIT_FAILURE);
	init(argc, argv, envp, &info);
	if (info.limiter != NULL && argc < 6)
		exit(EXIT_FAILURE);
	if (info.limiter != NULL)
		here_doc_process(&info);
	infile_process(&info, envp);
	middle_process(&info, envp);
	outfile_process(&info, envp);
	while (info.cmds_len--)
	{
		pid = wait(&status);
		if (pid == info.child)
			last_exit_code = WEXITSTATUS(status);
	}
	if (info.limiter != NULL)
		unlink(info.infile);
	exit(last_exit_code);
}
