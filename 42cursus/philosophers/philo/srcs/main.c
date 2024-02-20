/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/20 17:05:26 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ph_print_died(t_info *info, int idx)
{
	pthread_mutex_lock(info->print_mutex);
	set_is_one_die(info, TRUE);
	printf("%d %d %s\n", get_ms(info), idx + 1, "died");
	pthread_mutex_unlock(info->print_mutex);
}

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
				ph_print_died(info, idx);
				break ;
			}
			idx++;
		}
		if (eat_done == info->num_philo)
			set_is_one_die(info, TRUE);
	}
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
	if (!init(&philos, &info))
		return (info_clear(&philos, &info, 1));
	if (!init_pthread(&philos, &info))
		return (info_clear(&philos, &info, 1));
	if (!make_pthread(&philos, &info))
		return (info_clear(&philos, &info, 1));
	main_loop(&philos, &info);
	all_pthread_join(&philos, &info);
	info_clear(&philos, &info, 0);
	return (0);
}
