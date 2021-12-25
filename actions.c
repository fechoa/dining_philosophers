/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:25:08 by a1111             #+#    #+#             */
/*   Updated: 2021/11/13 13:27:25 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	simulation(t_program *data)
{
	int			i;
	pthread_t	spectator;

	i = 0;
	if (pthread_create(&spectator, NULL, (void *)check_meal, data) != SUCCESS)
		return (false);
	while (i < data->values_input->phil_num)
	{
		if (pthread_create(&data->philos[i].thread_id, NULL,
				(void *)living, &(data->philos[i])) != SUCCESS)
			return (false);
		usleep(100);
		i++;
	}
	if (pthread_join(spectator, NULL) != SUCCESS)
		return (false);
	return (true);
}

void	*living(t_philo *philo)
{
	while (1)
	{
		eating(philo);
		philo->count_eat++;
		if (philo->values_input->add_eat != -1
			&& philo->count_eat == philo->values_input->add_eat)
			return (NULL);
		sleeping(philo);
		thinking(philo);
	}
	return (NULL);
}

void	eating(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	draw_action(philo, TAKEN_LEFT_FORK, do_newtime(philo->values_input->start));
	pthread_mutex_lock(philo->right_fork);
	draw_action(philo, TAKEN_RIGHT_FORK,
		do_newtime(philo->values_input->start));
	draw_action(philo, EATING, do_newtime(philo->values_input->start));
	philo->last_eat = do_newtime(philo->values_input->start);
	my_usleep(philo->values_input->eat_time);
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

void	sleeping(t_philo *philo)
{
	draw_action(philo, SLEEPING, do_newtime(philo->values_input->start));
	my_usleep(philo->values_input->sleep_time);
}

void	thinking(t_philo *philo)
{
	draw_action(philo, THINKING, do_newtime(philo->values_input->start));
}
