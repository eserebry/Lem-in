/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:00:50 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/26 03:14:29 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*get_end(t_room *start)
{
	t_room *tmp;

	tmp = start;
	while (tmp->way)
		tmp = tmp->way;
	return (tmp);
}

void	print_output(int ant, char *room)
{
	ft_putchar('L');
	ft_putnbr(ant);
	ft_putchar('-');
	ft_putstr(room);
	ft_putchar(' ');
}

/*
**printing out ants while solution path exist, returns number of ants
*/

int		move_the_ants(t_room *start)
{
	t_room	*tmp;
	int		count;
	int		ants_num;

	tmp = get_end(start);
	ants_num = tmp->ants_num;
	count = tmp->ants_num;
	while (tmp->prev)
	{
		if (tmp->prev->ants_num > 0)
		{
			tmp->ants_num++;
			tmp->prev->ants_num--;
			count++;
			print_output(count, tmp->name);
		}
		tmp = tmp->prev;
	}
	ft_putchar('\n');
	return (ants_num);
}

void	solve(t_lemin *lemin)
{
	lemin->way->ants_num = lemin->ants_num;
	while ((move_the_ants(lemin->way)) != lemin->ants_num)
		;
}
