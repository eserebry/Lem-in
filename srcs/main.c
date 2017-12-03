/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/14 21:46:55 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/26 03:14:45 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_lemin	*init_struct(int argc)
{
	t_lemin *new;

	new = (t_lemin *)ft_memalloc(sizeof(t_lemin));
	new->ants_num = 0;
	new->rooms_num = 0;
	new->links_num = 0;
	new->rooms = NULL;
	new->links = NULL;
	new->start_on = 0;
	new->end_on = 0;
	new->tmp = NULL;
	new->input = NULL;
	return (new);
}

int		main(int argc, char **argv)
{
	t_lemin *lemin;
	t_room	*room;

	lemin = init_struct(argc);
	if (argc != 2 || (ft_strcmp(argv[1], "-c")) != 0)
	{
		ft_printf("{STC:RD}lem_in usage: ./lem_in [-c] < [map]\n" NONE);
		exit(1);
	}
	if (!get_input(lemin))
	{
		ft_printf("{STC:RD}Error\n" NONE);
		free_all(lemin);
		return (0);
	}
	create_solution_path(lemin, lemin->rooms);
	ft_printf("%s\n", lemin->input);
	solve(lemin);
	free_all(lemin);
	return (0);
}
