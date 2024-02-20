/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_type.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/20 14:45:41 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TYPE_H
# define PHILO_TYPE_H

# define TRUE 1
# define FALSE 0

typedef struct s_info
{
	int				num_philo;
	long long		time_to_die;
	long long		time_to_eat;
	long long		time_to_sleep;
	int				must_eat;
	int				is_one_die;
	struct timeval	start_time;
	struct timeval	now_time;
	int				*fork_status;
	pthread_mutex_t	*fork_list;
	pthread_mutex_t	*print_mutex;
	pthread_mutex_t	*is_one_die_mutex;
}	t_info;

typedef struct s_philo
{
	t_info			*info;
	pthread_t		pt;
	int				num;
	int				left_fork;
	int				right_fork;
	int				eat_cnt;
	long long		last_eat;
	pthread_mutex_t	*eat_cnt_mutex;
	pthread_mutex_t	*last_eat_mutex;
}	t_philo;

#endif
