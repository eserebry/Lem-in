/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eserebry <eserebry@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:50:39 by eserebry          #+#    #+#             */
/*   Updated: 2017/11/26 03:08:57 by eserebry         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../libft/includes/libft.h"
# include "../libft/ft_printf/includes/ft_printf.h"

typedef struct		s_room
{
	int				ants_num;
	int				doors_num;
	int				start;
	int				end;
	char			**door_names;
	char			*name;
	struct s_room	*next;
	struct s_room	*prev;
	struct s_room	*way;
	int				checked;
	int				path;
	int				pos;
}					t_room;

typedef struct		s_link
{
	char			*name1;
	char			*name2;
	struct s_link	*next;
}					t_link;

typedef struct		s_lemin
{
	int				ants_num;
	int				rooms_num;
	int				links_num;
	int				start_on;
	int				end_on;
	struct s_room	*rooms;
	struct s_link	*links;
	struct s_room	*way;
	struct s_room	*tmp;
	char			*input;
}					t_lemin;

/*
** ft_doors
*/
void				add_doors(t_lemin *lemin);
/*
** ft_links
*/
int					get_links(t_lemin *lemin, char *line);
/*
** ft_rooms
*/
void				add_room(t_lemin *lemin, char *line);
/*
** ft_recursion
*/
int					searching_path(t_lemin *lemin, char *door_name, int y);
/*
** ft_solution
*/
t_room				*start_search(t_room *room);
void				create_solution_path(t_lemin *lemin, t_room *rooms);
/*
** display_management
*/
int					validate_input(t_lemin *lemin);
int					validate_path(t_lemin *lemin, t_room *rooms);
int					display_rooms(t_lemin *lemin);
/*
** free_all
*/
void				free_all(t_lemin *lemin);
/*
** ft_ants
*/
int					check_ants(char *str);
int					get_ants(t_lemin *lemin, char *line);
/*
** ft_input
*/
int					get_input(t_lemin *lemin);
/*
** main
*/
int					end_room(t_lemin *lemin, t_room *tmp, int y);
int					part_of_path(t_room *tmp, int y);
/*
** ft_solve
*/
void				solve(t_lemin *lemin);

#endif
