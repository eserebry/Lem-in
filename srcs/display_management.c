/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 06:55:20 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/25 02:23:12 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	display_error(t_lemin *lemin)
{
	ft_printf("{STC:GR}Look at what we've got here:\n" NONE);
	if (lemin->ants_num == 0)
		ft_printf("{STC:RD}No ants\n" NONE);
	else
		ft_printf("{STC:DG}%d ants\n" NONE, lemin->ants_num);
	if (lemin->rooms_num == 0)
		ft_printf("{STC:RD}No rooms\n" NONE);
	else
		ft_printf("{STC:LB}%d rooms\n" NONE, lemin->rooms_num);
	if (lemin->links_num == 0)
		ft_printf("{STC:RD}No doors\n" NONE);
	else
		ft_printf("{STC:LY}%d doors\n" NONE, lemin->links_num);
}

/*
**validating input and displaing error msg
*/

int		validate_input(t_lemin *lemin)
{
	int check;

	check = 1;
	if (check == 1)
		display_error(lemin);
	if (lemin->ants_num == 0 || lemin->rooms_num == 0 || lemin->links_num == 0)
		check = 0;
	if (!display_rooms(lemin))
		check = 0;
	if (check == 0)
		return (0);
	if (!validate_path(lemin, lemin->rooms))
	{
		check = 0;
		ft_printf("{STC:RD}No, there is no way.\n" NONE);
	}
	else
		ft_printf("{STC:LR}Yes, there is a way!\n" NONE);
	return (check);
}

/*
**looking for a possible path,  if it's exist
*/

int		validate_path(t_lemin *lemin, t_room *rooms)
{
	t_room	*tmp;
	int		x;
	int		y;

	tmp = start_search(rooms);
	y = 0;
	tmp->checked = 1;
	tmp->pos = y;
	tmp->path = 1;
	if (tmp->doors_num == 0)
		return (0);
	x = -1;
	while (tmp->door_names[++x])
	{
		if (searching_path(lemin, tmp->door_names[x], y))
			return (1);
	}
	return (0);
}

/*
**validating if exit and start are exist and displpay the result
*/

int		display_rooms(t_lemin *lemin)
{
	int		count;
	int		start;
	int		end;
	t_room	*tmp;

	tmp = lemin->rooms;
	start = 0;
	end = 0;
	while (tmp)
	{
		if (tmp->start == 1)
			start = 1;
		if (tmp->end == 1)
			end = 1;
		tmp = tmp->next;
	}
	if (start == 1 && end == 1)
	{
		ft_printf("{STC:LG}##start and ##end are exist\n" NONE);
		return (1);
	}
	else
		ft_printf("{STC:RD}Missing start and/or end \n" NONE);
	return (0);
}
