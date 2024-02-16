/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/17 04:20:05 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ph_calloc(size_t count, size_t size)
{
	void	*res;
	size_t	byte;

	byte = count * size;
	if (size != 0 && byte / size != count)
		return (0);
	res = malloc(count * size);
	if (!res)
		return (res);
	memset(res, 0, byte);
	return (res);
}

void	info_clear(t_philo **philos, t_info *info)
{
	int	idx;

	idx = 0;
	while (idx < info->num_philo)
	{
		free((*philos)[idx].last_eat_mutex);
		free((*philos)[idx].eat_cnt_mutex);
		idx++;
	}
	free(*philos);
	free(info->fork_list);
	free(info->print_mutex);
	free(info->is_one_die_mutex);
}

void	loop_sleep(long long ms)
{
	struct timeval	now_time;
	struct timeval	start_time;

	gettimeofday(&start_time, NULL);
	usleep(ms * 700);
	while (1)
	{
		gettimeofday(&now_time, NULL);
		if (((now_time.tv_sec - start_time.tv_sec) * 1000000 + \
			now_time.tv_usec - start_time.tv_usec) >= ms * 1000)
			break ;
		usleep(100);
	}
}

int	get_ms(t_info *info)
{
	struct timeval	now_time;

	gettimeofday(&now_time, NULL);
	return ((now_time.tv_sec - info->start_time.tv_sec) * 1000 + \
			(now_time.tv_usec - info->start_time.tv_usec) / 1000);
}

void	ph_print(t_info *info, int idx, char *str)
{
	if (get_is_one_die(info) == TRUE)
		return ;
	pthread_mutex_lock(info->print_mutex);
	printf("%d %d %s\n", get_ms(info), idx + 1, str);
	pthread_mutex_unlock(info->print_mutex);
}
