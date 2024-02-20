/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tajeong <tajeong@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/15 15:23:33 by tajeong           #+#    #+#             */
/*   Updated: 2024/02/20 16:41:15 by tajeong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "philo_include.h"
# include "philo_type.h"

/* init.c */
int			make_pthread(t_philo **philos, t_info *info);
int			init_pthread(t_philo **philos, t_info *info);
int			init(t_philo **philos, t_info *info);

/* parser.c */
int			parse(int argc, char *argv[], t_info *info);

/* utils1.c */
int			ph_atoi(const char *str);
int			get_is_one_die(t_info *info);
void		set_is_one_die(t_info *info, int value);

/* utils2.c */
void		*ph_calloc(size_t count, size_t size);
int			info_clear(t_philo **philos, t_info *info, int exit_code);
int			get_ms(t_info *info);
void		ph_print(t_info *info, int idx, char *str);
void		loop_sleep(long long ms);

/* utils3.c */
long long	get_last_eat(t_philo *philo);
void		set_last_eat(t_philo *philo, long long value);
int			get_eat_cnt(t_philo *philo);
void		set_eat_cnt(t_philo *philo, int value);

/* utils4.c */
int			get_left_fork_status(t_philo *philo, t_info *info);
void		set_left_fork_status(t_philo *philo, t_info *info, int value);
int			get_right_fork_status(t_philo *philo, t_info *info);
void		set_right_fork_status(t_philo *philo, t_info *info, int value);
int			try_left_fork_status(t_philo *philo, t_info *info);
int			try_right_fork_status(t_philo *philo, t_info *info);
#endif
