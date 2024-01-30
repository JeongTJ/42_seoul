/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/28 16:51:04 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/pipex_bonus.h"

static void	cmd_exec(t_info *info, char	**cmd, char **envp)
{
	int		idx;
	char	*dir;

	idx = 0;
	while (info->paths[idx])
	{
		if (ft_strchr(cmd[0], '/') != NULL)
			dir = cmd[0];
		else
			dir = ft_strjoin(info->paths[idx], cmd[0]);
		if (dir == NULL)
			error_manager("malloc error", EXIT_FAILURE);
		if (access(dir, F_OK) == 0)
			if (execve(dir, cmd, envp) == -1)
				error_manager(cmd[0], 126);
		if (ft_strchr(cmd[0], '/') == NULL)
			free(dir);
		idx++;
	}
	ft_putstr_fd("pipex: ", 2);
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	exit(127);
}

void	infile_process(t_info *info, char **envp)
{
	pipe(info->pipe_fd);
	info->child = fork();
	if (info->child == 0)
	{
		info->input_fd = open(info->infile, O_RDONLY);
		if (info->input_fd == -1)
			error_manager(info->infile, EXIT_FAILURE);
		dup2(info->pipe_fd[1], 1);
		dup2(info->input_fd, 0);
		close(info->pipe_fd[0]);
		close(info->pipe_fd[1]);
		close(info->input_fd);
		cmd_exec(info, info->cmds[0], envp);
	}
	close(info->pipe_fd[1]);
	info->input_fd = info->pipe_fd[0];
}

void	middle_process(t_info *info, char **envp)
{
	int	idx;

	idx = 1;
	while (idx < info->cmds_len - 1)
	{
		pipe(info->pipe_fd);
		info->child = fork();
		if (info->child == 0)
		{
			dup2(info->input_fd, 0);
			dup2(info->pipe_fd[1], 1);
			close(info->input_fd);
			close(info->pipe_fd[0]);
			close(info->pipe_fd[1]);
			cmd_exec(info, info->cmds[idx], envp);
		}
		close(info->pipe_fd[1]);
		close(info->input_fd);
		info->input_fd = info->pipe_fd[0];
		idx++;
	}
}

void	outfile_process(t_info *info, char **envp)
{
	int		outfile_fd;

	outfile_fd = open(info->outfile, O_WRONLY | \
				(O_TRUNC * (info->limiter == NULL)) | \
				(O_APPEND * (info->limiter != NULL)) | \
				O_CREAT, S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH);
	if (outfile_fd == -1)
		error_manager(info->outfile, EXIT_FAILURE);
	info->child = fork();
	if (info->child == 0)
	{
		dup2(outfile_fd, 1);
		dup2(info->input_fd, 0);
		close(outfile_fd);
		close(info->input_fd);
		cmd_exec(info, info->cmds[info->cmds_len - 1], envp);
	}
	close(info->input_fd);
	close(outfile_fd);
}

void	here_doc_process(t_info *info)
{
	const int	limiter_len = ft_strlen(info->limiter);
	char		*line;
	int			dummy_fd;

	dummy_fd = open(info->infile, O_WRONLY | O_TRUNC | O_CREAT, \
							777);
	while (1)
	{
		line = get_next_line(0);
		if (line == NULL || \
			ft_strncmp(line, info->limiter, limiter_len + 1) == 0)
			break ;
		ft_putstr_fd(line, dummy_fd);
		free(line);
	}
	free(line);
	close(dummy_fd);
}
