/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/30 07:12:41 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/25 02:29:16 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

/*
** checking if ##start and ##end are found
*/

int		check_start_end(t_lemin *lemin, char *line)
{
	if ((ft_strcmp(line, "##start")) == 0)
	{
		lemin->check_start = 1;
		return (1);
	}
	else if ((ft_strcmp(line, "##end")) == 0)
	{
		lemin->check_end = 1;
		return (1);
	}
	return (0);
}

int		get_input(t_lemin *lemin)
{
	int		count;
	char	*line;

	count = 0;
	lemin->input = ft_strnew(1);
	while (ft_get_next_line(0, &line) > 0)
	{
		if (get_ants(lemin, line))
			;
		else if (add_rooms(lemin, line))
			;
		else if (add_links(lemin, line))
			;
		else if (check_start_end(lemin, line))
			;
		lemin->input = ft_strjoin_free(lemin->input, line, 1);
		lemin->input = ft_strjoin_free(lemin->input, "\n", 1);
		free(line);
		count++;
	}
	add_doors(lemin);
	if (!validate_input(lemin))
		return (0);
	return (1);
}
