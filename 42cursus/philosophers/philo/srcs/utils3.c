/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/17 02:37:03 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long long	get_last_eat(t_philo *philo)
{
	long long	res;

	pthread_mutex_lock(philo->last_eat_mutex);
	res = philo->last_eat;
	pthread_mutex_unlock(philo->last_eat_mutex);
	return (res);
}

void	set_last_eat(t_philo *philo, long long value)
{
	pthread_mutex_lock(philo->last_eat_mutex);
	philo->last_eat = value;
	pthread_mutex_unlock(philo->last_eat_mutex);
}

int	get_eat_cnt(t_philo *philo)
{
	int	res;

	pthread_mutex_lock(philo->eat_cnt_mutex);
	res = philo->eat_cnt;
	pthread_mutex_unlock(philo->eat_cnt_mutex);
	return (res);
}

void	set_eat_cnt(t_philo *philo, int value)
{
	pthread_mutex_lock(philo->eat_cnt_mutex);
	philo->eat_cnt = value;
	pthread_mutex_unlock(philo->eat_cnt_mutex);
}
