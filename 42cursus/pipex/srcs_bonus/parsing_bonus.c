/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/18 21:52:05 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_bonus/pipex_bonus.h"

static void	remove_back_slash_before_quotes(char *cmd)
{
	const int	cmd_len = ft_strlen(cmd);
	int			idx;

	idx = 0;
	while (cmd_len > 1 && idx < cmd_len - 1)
	{
		if (cmd[idx] == '\\' && (cmd[idx + 1] == '\'' || \
			cmd[idx + 1] == '\"' || cmd[idx + 1] == '\\'))
			ft_memmove(&cmd[idx], &cmd[idx + 1], cmd_len - idx);
		idx++;
	}
}

static void	remove_back_slash(char ***cmds)
{
	int	cmd_idx;
	int	flag_idx;

	cmd_idx = 0;
	while (cmds[cmd_idx])
	{
		flag_idx = 0;
		while (cmds[cmd_idx][flag_idx])
		{
			remove_back_slash_before_quotes(cmds[cmd_idx][flag_idx]);
			flag_idx++;
		}
		cmd_idx++;
	}
}

static int	get_path_idx(char **envp)
{
	int	idx;

	idx = 0;
	while (envp[idx])
	{
		if (ft_strnstr(envp[idx], "PATH=", 5) != NULL)
			return (idx);
		idx++;
	}
	return (-1);
}

static void	init_path(char **envp, t_info *info)
{
	char	**envp_split;
	char	*tmp;

	if (get_path_idx(envp) == -1)
		envp_split = \
		ft_split("/usr/gnu/bin:/usr/local/bin:/bin:/usr/bin:.", ':');
	else
		envp_split = ft_split(envp[get_path_idx(envp)], ':');
	if (envp_split == NULL)
		error_manager("malloc error", EXIT_FAILURE);
	info->paths = envp_split;
	if (info->paths[0] == NULL)
		return ;
	tmp = ft_strjoin(&(*envp_split)[5], "/");
	free(*envp_split);
	*envp_split = tmp;
	envp_split++;
	while (*envp_split)
	{
		tmp = ft_strjoin(*envp_split, "/");
		free(*envp_split);
		*envp_split = tmp;
		envp_split++;
	}
}

void	init(int argc, char **argv, char **envp, t_info *info)
{
	int	cmd_start_idx;

	cmd_start_idx = 2;
	info->infile = argv[1];
	info->outfile = argv[argc - 1];
	info->limiter = NULL;
	if (ft_strncmp(info->infile, "here_doc", 9) == 0)
	{
		cmd_start_idx = 3;
		info->limiter = ft_strjoin(argv[2], "\n");
		if (info->limiter == NULL)
			error_manager("malloc error", EXIT_FAILURE);
		info->infile = ".tmp";
	}
	init_cmds(cmd_start_idx, argc, argv, info);
	init_path(envp, info);
	remove_back_slash(info->cmds);
}
