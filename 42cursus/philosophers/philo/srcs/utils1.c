/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/17 04:20:42 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ph_atoi(const char *str)
{
	int				sign;
	unsigned long	res;

	sign = 1;
	res = 0;
	while ((*str == ' ' || *str == '\v' || *str == '\n' || \
			*str == '\t' || *str == '\f' || *str == '\r') && *str)
		str++;
	if (*str == '-' || *str == '+')
		if (*str++ == '-')
			sign *= -1;
	while ('0' <= *str && *str <= '9' && *str)
	{
		if (res * 10 + (unsigned long)(*str - '0') > \
			(unsigned long)9223372036854775807 || \
			res > (unsigned long)9223372036854775807 / 10)
			return (-1 + (sign == -1));
		res *= 10;
		res += (unsigned long)(*str - '0');
		str++;
	}
	return ((int)(sign * res));
}

int	get_is_one_die(t_info *info)
{
	int	res;

	pthread_mutex_lock(info->is_one_die_mutex);
	res = info->is_one_die;
	pthread_mutex_unlock(info->is_one_die_mutex);
	return (res);
}

void	set_is_one_die(t_info *info, int value)
{
	pthread_mutex_lock(info->is_one_die_mutex);
	info->is_one_die = value;
	pthread_mutex_unlock(info->is_one_die_mutex);
}
