/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/20 16:28:01 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ph_isalpha(char c)
{
	return (('A' <= c && c <= 'Z') || \
			('a' <= c && c <= 'z'));
}

int	isvalid_argv(int argc, char *argv[])
{
	int	argv_idx;
	int	str_idx;

	argv_idx = 1;
	while (argv_idx < argc)
	{
		str_idx = 0;
		while (argv[argv_idx][str_idx])
		{
			if (ph_isalpha(argv[argv_idx][str_idx]))
				return (FALSE);
			str_idx++;
		}
		argv_idx++;
	}
	return (TRUE);
}

int	parse(int argc, char *argv[], t_info *info)
{
	if (!(argc == 5 || argc == 6))
		return (FALSE);
	if (!isvalid_argv(argc, argv))
		return (FALSE);
	info->num_philo = ph_atoi(argv[1]);
	if (info->num_philo <= 0)
		return (FALSE);
	info->time_to_die = ph_atoi(argv[2]);
	if (info->time_to_die <= 0)
		return (FALSE);
	info->time_to_eat = ph_atoi(argv[3]);
	if (info->time_to_eat <= 0)
		return (FALSE);
	info->time_to_sleep = ph_atoi(argv[4]);
	if (info->time_to_sleep <= 0)
		return (FALSE);
	if (argc == 6)
	{
		info->must_eat = ph_atoi(argv[5]);
		if (info->must_eat <= 0)
			return (FALSE);
	}
	else
		info->must_eat = -1;
	return (TRUE);
}
