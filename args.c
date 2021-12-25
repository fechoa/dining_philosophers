/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:51:10 by a1111             #+#    #+#             */
/*   Updated: 2021/11/12 16:52:06 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	is_num(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		if (str[i] < '0' || str[i] > '9')
			return (false);
	return (true);
}

int	atoi_args(char *str)
{
	long	num;

	if (is_num(str) == false)
		return (BAD_RESULT);
	num = 0;
	while (*str)
	{
		num = num * 10 + *str - 48;
		str++;
	}
	if (num >= 0 && num <= MAX_INT)
		return ((int)num);
	return (BAD_RESULT);
}

bool	is_valid_data(int argc, char *argv[])
{
	if (atoi_args(argv[1]) < 1
		|| atoi_args(argv[2]) < 0
		|| atoi_args(argv[3]) < 0
		|| atoi_args(argv[4]) < 0
		|| (argc == 6 && atoi_args(argv[5]) < 1))
		return (false);
	return (true);
}

bool	loading_data_values_input(t_values_input *values_inputs,
	int argc, char *argv[])
{
	if (is_valid_data(argc, argv) == false)
		return (false);
	values_inputs->phil_num = atoi_args(argv[1]);
	values_inputs->die_time = atoi_args(argv[2]);
	values_inputs->eat_time = atoi_args(argv[3]);
	values_inputs->sleep_time = atoi_args(argv[4]);
	if (argc == 6)
		values_inputs->add_eat = atoi_args(argv[5]);
	else
		values_inputs->add_eat = -1;
	values_inputs->start = do_newtime(0);
	return (true);
}
