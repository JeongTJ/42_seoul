/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/20 16:29:31 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	try_left_fork_status(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->fork_list[philo->left_fork]);
	if (info->fork_status[philo->left_fork] == FALSE)
	{
		info->fork_status[philo->left_fork] = TRUE;
		pthread_mutex_unlock(&info->fork_list[philo->left_fork]);
		return (TRUE);
	}
	pthread_mutex_unlock(&info->fork_list[philo->left_fork]);
	return (FALSE);
}

int	try_right_fork_status(t_philo *philo, t_info *info)
{
	pthread_mutex_lock(&info->fork_list[philo->right_fork]);
	if (info->fork_status[philo->right_fork] == FALSE)
	{
		info->fork_status[philo->right_fork] = TRUE;
		pthread_mutex_unlock(&info->fork_list[philo->right_fork]);
		return (TRUE);
	}
	pthread_mutex_unlock(&info->fork_list[philo->right_fork]);
	return (FALSE);
}

void	set_left_fork_status(t_philo *philo, t_info *info, int value)
{
	pthread_mutex_lock(&info->fork_list[philo->left_fork]);
	info->fork_status[philo->left_fork] = value;
	pthread_mutex_unlock(&info->fork_list[philo->left_fork]);
}

void	set_right_fork_status(t_philo *philo, t_info *info, int value)
{
	pthread_mutex_lock(&info->fork_list[philo->right_fork]);
	info->fork_status[philo->right_fork] = value;
	pthread_mutex_unlock(&info->fork_list[philo->right_fork]);
}
