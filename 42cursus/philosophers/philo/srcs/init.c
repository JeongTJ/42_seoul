/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/20 16:43:31 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*all(t_philo *philo, int idx)
{
	while (get_is_one_die(philo->info) == FALSE)
	{
		while (!try_left_fork_status(philo, philo->info))
			usleep(100);
		ph_print(philo->info, idx, "has taken a fork");
		while (!try_right_fork_status(philo, philo->info) && \
				!get_is_one_die(philo->info))
			usleep(100);
		ph_print(philo->info, idx, "has taken a fork");
		set_last_eat(philo, get_ms(philo->info));
		ph_print(philo->info, idx, "is eating");
		loop_sleep(philo->info->time_to_eat);
		set_eat_cnt(philo, get_eat_cnt(philo) + 1);
		set_left_fork_status(philo, philo->info, FALSE);
		set_right_fork_status(philo, philo->info, FALSE);
		ph_print(philo->info, idx, "is sleeping");
		loop_sleep(philo->info->time_to_sleep);
		ph_print(philo->info, idx, "is thinking");
	}
	return (NULL);
}

void	*loop(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->num % 2 == 1)
		return (all(philo, philo->num));
	else
	{
		ph_print(philo->info, philo->num, "is thinking");
		loop_sleep(philo->info->time_to_eat);
		return (all(philo, philo->num));
	}
}

int	make_pthread(t_philo **philos, t_info *info)
{
	int	cnt;

	cnt = 0;
	gettimeofday(&info->start_time, NULL);
	while (cnt < info->num_philo)
	{
		pthread_create(&((*philos)[cnt].pt), NULL, loop, &(*philos)[cnt]);
		cnt++;
	}
	return (TRUE);
}

int	init_pthread(t_philo **philos, t_info *info)
{
	int	cnt;

	cnt = 0;
	while (cnt < info->num_philo)
	{
		(*philos)[cnt].info = info;
		(*philos)[cnt].left_fork = cnt;
		(*philos)[cnt].right_fork = (cnt + 1) % info->num_philo;
		(*philos)[cnt].num = cnt;
		(*philos)[cnt].last_eat_mutex = ph_calloc(1, sizeof(pthread_mutex_t));
		if ((*philos)[cnt].last_eat_mutex == NULL)
			return (FALSE);
		(*philos)[cnt].eat_cnt_mutex = ph_calloc(1, sizeof(pthread_mutex_t));
		if ((*philos)[cnt].eat_cnt_mutex == NULL)
			return (FALSE);
		pthread_mutex_init((*philos)[cnt].last_eat_mutex, NULL);
		pthread_mutex_init((*philos)[cnt].eat_cnt_mutex, NULL);
		cnt++;
	}
	return (TRUE);
}

int	init(t_philo **philos, t_info *info)
{
	int	cnt;

	*philos = ph_calloc(info->num_philo, sizeof(t_philo));
	if (*philos == NULL)
		return (FALSE);
	info->fork_list = ph_calloc(info->num_philo, sizeof(pthread_mutex_t));
	if (info->fork_list == NULL)
		return (FALSE);
	info->fork_status = ph_calloc(info->num_philo, sizeof(int));
	if (info->fork_status == NULL)
		return (FALSE);
	info->print_mutex = ph_calloc(1, sizeof(pthread_mutex_t));
	if (info->print_mutex == NULL)
		return (FALSE);
	info->is_one_die_mutex = ph_calloc(1, sizeof(pthread_mutex_t));
	if (info->is_one_die_mutex == NULL)
		return (FALSE);
	pthread_mutex_init(info->print_mutex, NULL);
	pthread_mutex_init(info->is_one_die_mutex, NULL);
	cnt = 0;
	while (cnt < info->num_philo)
		pthread_mutex_init(&info->fork_list[cnt++], NULL);
	return (TRUE);
}
