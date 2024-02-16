/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_process_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/11 17:03:12 by junhylee          #+#    #+#             */
/*   Updated: 2024/02/13 19:03:49 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

void	signal_handle(int signo)
{
	if (signo == SIGINT)
	{
		ft_putchar_fd('\n', 1);
		rl_replace_line("", 0);
		rl_on_new_line();
		rl_redisplay();
		g_last_exitcode = 1;
	}
}

void	init_minishell(void)
{
	g_last_exitcode = 0;
	rl_catch_signals = 0;
	signal(SIGINT, signal_handle);
	signal(SIGQUIT, SIG_IGN);
}

int	is_str_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

void	ctrl_d(void)
{
	ft_putendl_fd("exit", 1);
	exit(g_last_exitcode);
}
