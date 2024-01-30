/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_split.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 19:03:52 by tajeong           #+#    #+#             */
/*   Updated: 2024/01/18 21:48:32 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/pipex.h"

static void	split_cmd(char *cmd, int len)
{
	int	quotes_flag;
	int	idx;

	quotes_flag = ' ';
	idx = 0;
	while (idx < len)
	{
		if (quotes_flag == ' ' && cmd[idx] == ' ')
			cmd[idx] = '\0';
		else if ((quotes_flag == '\'' && cmd[idx] == '\'' && \
				idx > 0 && cmd[idx - 1] != '\\') || \
				(quotes_flag == '\"' && cmd[idx] == '\"' && \
				idx > 0 && cmd[idx - 1] != '\\'))
		{
			cmd[idx] = '\0';
			quotes_flag = ' ';
		}
		if (quotes_flag == ' ' && ((cmd[idx] == '\'' || cmd[idx] == '\"') \
			&& idx > 0 && cmd[idx - 1] != '\\'))
		{
			quotes_flag = cmd[idx];
			cmd[idx] = '\0';
		}
		idx++;
	}
}

static int	get_split_size(char *cmd, int len)
{
	int	size;
	int	idx;

	size = 1;
	idx = 1;
	while (idx < len)
	{
		if (cmd[idx - 1] == '\0' && cmd[idx] != '\0')
			size++;
		idx++;
	}
	return (size);
}

static char	**cmd_split(char *cmd)
{
	const int	len = ft_strlen(cmd);
	char		**res;
	char		*tmp;
	int			res_size;
	int			idx;

	split_cmd(cmd, len);
	res_size = get_split_size(cmd, len);
	res = ft_calloc(res_size + 1, sizeof(char *));
	if (res == 0)
		error_manager("malloc error", EXIT_FAILURE);
	idx = 0;
	while (idx < res_size)
	{
		while (*cmd == '\0')
			cmd++;
		tmp = ft_substr(cmd, 0, ft_strlen(cmd));
		if (tmp == NULL)
			error_manager("malloc error", EXIT_FAILURE);
		res[idx] = tmp;
		while (*cmd != '\0')
			cmd++;
		idx++;
	}
	return (res);
}

void	init_cmds(int start_idx, int argc, char **argv, t_info *info)
{
	int	idx;

	idx = 0;
	info->cmds = ft_calloc(argc - start_idx, sizeof(char **));
	info->cmds_len = argc - start_idx - 1;
	if (info->cmds == NULL)
		error_manager("malloc error", EXIT_FAILURE);
	while (start_idx < argc - 1)
	{
		info->cmds[idx] = cmd_split(argv[start_idx]);
		start_idx++;
		idx++;
	}
}
