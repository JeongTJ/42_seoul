/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/19 18:48:46 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

typedef struct s_info
{
	char	*infile;
	char	*outfile;
	char	***cmds;
	int		cmds_len;
	char	*limiter;
	char	**paths;
	int		pipe_fd[2];
	int		input_fd;
	pid_t	child;
}			t_info;

/* error.c */
void	error_manager(char *cmd, int error_code);

/* parsing.c */
void	init(int argc, char **argv, char **envp, t_info *info);

/* cmd_split.c */
void	init_cmds(int start_idx, int argc, char **argv, t_info *info);

/* process.c */
void	infile_process(t_info *info, char **envp);
void	middle_process(t_info *info, char **envp);
void	outfile_process(t_info *info, char **envp);
void	here_doc_process(t_info *info);

#endif
