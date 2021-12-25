/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: a1111 <a1111@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/12 16:33:58 by a1111             #+#    #+#             */
/*   Updated: 2021/11/12 16:34:18 by a1111            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	args_error(void)
{
	write(2, RED_COLOR, lenstr(RED_COLOR));
	write(2, ERROR_ARGS, lenstr(ERROR_ARGS));
	write(2, RESET_COLOR, lenstr(RESET_COLOR));
	return (SUCCESS);
}

int	malloc_error(void)
{
	write(2, RED_COLOR, lenstr(RED_COLOR));
	write(2, ERROR_MALLOC, lenstr(ERROR_MALLOC));
	write(2, RESET_COLOR, lenstr(RESET_COLOR));
	return (SUCCESS);
}

int	values_inputs_error(void)
{
	write(2, RED_COLOR, lenstr(RED_COLOR));
	write(2, ERROR_VALUES_INPUTS, lenstr(ERROR_VALUES_INPUTS));
	write(2, RESET_COLOR, lenstr(RESET_COLOR));
	return (SUCCESS);
}
