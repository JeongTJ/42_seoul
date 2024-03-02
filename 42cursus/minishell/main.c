/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/28 21:54:00 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/13 19:03:52 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main.h"

int	g_last_exitcode;

int	main(int argc, char *argv[], char *envp[])
{
	t_list	*env;

	if (argv[1] != NULL)
		return (0);
	init_minishell();
	if (argc != 1)
		return (0);
	env = get_env_list(envp);
	loop_shell(env);
	exit(0);
	return (0);
}
