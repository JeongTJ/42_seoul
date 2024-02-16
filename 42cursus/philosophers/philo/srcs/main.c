/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/17 04:17:55 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	all_pthread_join(t_philo **philos, t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_philo)
	{
		pthread_join((*philos)[idx].pt, NULL);
		idx++;
	}
}

void	main_loop(t_philo **philos, t_info *info)
{
	int	idx;
	int	eat_done;

	while (get_is_one_die(info) == FALSE)
	{
		idx = 0;
		eat_done = 0;
		while (idx < info->num_philo)
		{
			if (info->must_eat != -1 && \
							get_eat_cnt(&(*philos)[idx]) >= info->must_eat)
				eat_done++;
			if (get_ms(info) - get_last_eat(&(*philos)[idx]) \
									> info->time_to_die)
			{
				ph_print(info, idx, "died");
				set_is_one_die(info, TRUE);
				break ;
			}
			idx++;
		}
		if (eat_done == info->num_philo)
			set_is_one_die(info, TRUE);
	}
	all_pthread_join(philos, info);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philos;

	info.is_one_die = FALSE;
	if (!parse(argc, argv, &info))
		return (1);
	gettimeofday(&(info.start_time), NULL);
	gettimeofday(&(info.now_time), NULL);
	init(&philos, &info);
	main_loop(&philos, &info);
	info_clear(&philos, &info);
	return (0);
}
