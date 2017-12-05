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
	ft_printf("{STC:LG}{SET:UL}{SET:RB}Look at what we've got here:\n" NN);
	if (lemin->ants_num == 0)
		ft_printf("{STC:RD}{SET:RB}*No ants*\n" NN);
	else
		ft_printf("{STC:DG}{SET:UL}{SET:RB}*%d ants*\n" NN, lemin->ants_num);
	if (lemin->rooms_num == 0)
		ft_printf("{STC:RD}{SET:RB}*No rooms*\n" NN);
	else
		ft_printf("{STC:LB}{SET:UL}{SET:RB}*%d rooms*\n" NN, lemin->rooms_num);
	if (lemin->links_num == 0)
		ft_printf("{STC:RD}{SET:RB}*No doors*\n" NN);
	else
		ft_printf("{STC:LY}{SET:UL}{SET:RB}*%d doors*\n" NN, lemin->links_num);
}

/*
**validating input and displaing error msg
*/

int		validate_input(t_lemin *lemin)
{
	int		check;
	t_room	*tmp;

	check = 1;
	if (check == 1)
		display_error(lemin);
	if (lemin->ants_num == 0 || lemin->rooms_num == 0 || lemin->links_num == 0)
		check = 0;
	if (!display_rooms(lemin, tmp))
		check = 0;
	if (check == 0)
		return (0);
	if (!validate_path(lemin, lemin->rooms))
	{
		check = 0;
		ft_printf("{STC:RD}{SET:UL}{SET:RB}No, there is no way.\n" NN);
	}
	else
		ft_printf("{STC:LG}{SET:UL}{SET:RB}Yes, there is a way!\n" NN);
	return (check);
}

/*
**validating if exit and start are exist and displpay the result
*/

int		display_rooms(t_lemin *lemin, t_room *tmp)
{
	int		start;
	int		end;

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
		ft_printf("{STC:GR}##start is exist\n{STC:BU}##end is exist\n" NN);
		return (1);
	}
	else if (start == 0 && end == 1)
		ft_printf("{STC:BU}##end is exist\n"NN"{STC:RD}##start is missing\n"NN);
	else if (start == 1 && end == 0)
		ft_printf("{STC:BU}##start is exist\n"NN"{STC:RD}Missing ##end \n" NN);
	return (0);
}
