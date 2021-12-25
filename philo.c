/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gkelsie <gkelsie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/09 12:39:10 by gkelsie           #+#    #+#             */
/*   Updated: 2021/11/13 13:18:42 by gkelsie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char *argv[])
{
	t_program	*program;

	if (argc != 6 && argc != 5)
		return (args_error() + FAILURE);
	program = program_init();
	if (program == NULL)
		return (malloc_error() + free_all_program(program, 0) + FAILURE);
	if (loading_data_values_input(program->values_input, argc, argv) == false)
		return (values_inputs_error() + free_all_program(program, 0) + FAILURE);
	if (status_init(program) == false)
		return (malloc_error() + free_all_program(program, 0) + FAILURE);
	if (philo_init(program, 0) == false)
		return (malloc_error() + free_all_program(program, 0) + FAILURE);
	if (simulation(program) == false)
		return (malloc_error() + free_all_program(program, 0) + FAILURE);
	free_all_program(program, 0);
	return (SUCCESS);
}
