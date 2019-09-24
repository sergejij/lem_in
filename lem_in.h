/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lshellie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 17:02:38 by lshellie          #+#    #+#             */
/*   Updated: 2019/08/22 17:02:39 by lshellie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_LEM_IN_H
# define LEM_IN_LEM_IN_H
# include "libft/libft.h"

#include <stdio.h>

# define ANTS 0
# define ROOMS 1
# define LINKS 2

typedef struct		s_sets
{
	int 			*set_rooms;
	int 			len;
	int 			turns;
	struct s_sets	*next;
}					t_sets;

typedef struct		s_lst
{
	int 			sum;
	t_sets			*sets;
	struct s_lst	*next;
}					t_lst;

typedef struct		s_links
{
	char 			**first;
	char 			**second;
}					t_links;

typedef struct		s_room
{
	char 			*name;
	int 			x;
	int 			y;
	int 			start;
	int 			end;
	int 			num_of_links;
	int 			*links;
	int				visited;
	int				sh;
	int 			forbbiden;
	int 			forb_new_way;
	int 			open;
	int				index_prev;
	int				weght;
	int 			color;
	int 			invisib;
	int				looked; //in use_shortest, fill arr index
}					t_room;

typedef struct		s_way
{
	int 			room1;
	int 			room2;
	int				shortest;
	int				forbbiden;
	int				invisible;
}					t_way;

typedef struct		s_path
{
	int 			*p;
	int				len;
}					t_path;

typedef struct		s_map
{
	int 			ants;
	int 			num_of_rooms;
	int 			num_of_ways;
	int 			index_end;
	int 			index_start;
	int 			*forbidden_rooms;
	t_room			*rooms;
	t_way			*ways;
	t_path			*paths;
	t_lst			*sets;
	int				*sh_path;
}					t_map;

/*
 * set_basic.c
 */

void		set_new_set(t_lst **lst, t_lst *new);
t_lst		*new_lst(void);
void		free_lst(t_lst *lst);
t_sets		*new_set(t_map *nest, int cur);
void		put_set(t_lst *lst, t_sets *new);

/*
 *  make_map.c
 */

t_map		*make_map(char *map);

/*
 * free.c
 */

void		free_rooms(t_room **rooms, int num);
void		free_map(t_map **map);
void		show_map(t_map *map);

/*
 * read_and_save.c
 */

char 			*read_and_save(void);
char			*ft_free_split(char **split, int num);

/*
 * validation.c
 */

int		check_duplicates_links(char **split, int i);
int		validation(char *map);
int 	check_duplicates(t_room *rooms, int num);
int 	check_links(char **split);

/*
 * define.c
 */

int		is_number(char *line);
int		is_room(char *line);
int		is_ant(char *line);
int		is_link(char *line);

/*
 * find.c
 */

int		find_links(char **split);
int		find_rooms(char **split);
int		find_ants(char **split);
int 	find_index_by_name(t_room *rooms, int num, char *name);
int		find_start(t_map *nest);

/*
 * check_parts.c
 */

int 	check_part1(char **split, int *mas);
int 	check_part2(char **split, int *mas);
int 	check_part3(char **split, int *mas);
int 	check_part4(char **split);

/*
 * make_links.c
 */

int 		make_links(t_map *map, char **split);
void		link_rooms(t_map *map, t_links *links);

/*
 * solution.c
 */

void main_solution(t_map *nest);
void	ft_solution(t_map *nest);


/*
 * ways.c
 */

int		ft_count_ways(t_map *nest);
void	ft_malloc_and_fill_ways(t_map *nest);
int		ft_find_index_ways(t_map *nest, int first, int second);
void	ft_record_ways(t_map *nest,	int j,	int i, int end);

/*
 * auxiliary.c
 */

void 	ft_initialization_weight(t_map *nest);
int		ft_room_less_weight(t_map *nest, int index, int i);
int		ft_check_next_rooms(t_map *nest, int current);
int		ft_find_shortest(t_map *nest, int i);

/*
 * auxiliary.c
 */

int		ft_found_start(t_map *nest);
void	ft_write_shortest(t_map *nest);

/*
 * find_new_paths.c
 */

void		ft_find_new_paths(t_map *nest, int count_path);

/*
 * use_shortest.c
 */

void		ft_use_shortest(t_map *nest);

/*
 * line_breaker.c
 */

int			ft_find_intersections(t_map *nest, int index_forb, int i, int j);
void		ft_delete_ways(t_map *nest, int start, int end, int i);
void		ft_line_breaker(t_map *nest, int index_forb);

/*
 * sets.c
 */

void 		find_sets(t_map *nest);
int			make_set(t_map *nest, t_lst *lst, int cur);
int 		count_sets_len(t_map *nest, int cur);

#endif
