#include "lem_in.h"

int	ft_found_start(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_rooms)
		if (nest->rooms[i].start)
			return (i);
	return (-1);
}

int	ft_found_end(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_rooms)
		if (nest->rooms[i].end)
			return (i);
	return (0);
}

void 	ft_initialis_weight(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_rooms)
	{
		if (nest->rooms[i].start)
			continue;
		else if (!nest->rooms[i].forbbiden)
			nest->rooms[i].weght = 2147483640;
	}
}

/*void	ft_find_shortest(t_map *nest, int start, int prev)
{
	int 	cur;
	t_room	*rooms;
	int 	i;

	i = -1;
	rooms = nest->rooms;
	if (prev >= 0)
		rooms[prev].visited = 1;
	cur = start;
	while (++i < rooms[cur].num_of_links)
	{
		if (!rooms[rooms[cur].links[i]].visited && (!rooms[rooms[cur].links[i]].weght || rooms[rooms[cur].links[i]].weght > 1 + rooms[cur].weght))
			rooms[rooms[cur].links[i]].weght = 1 + rooms[cur].weght;
	}
	i = -1;
	while (++i < rooms[cur].num_of_links)
	{
		if (!rooms[rooms[cur].links[i]].visited)
			ft_find_shortest(nest, rooms[cur].links[i], cur);
	}
	if (prev >= 0)
		rooms[prev].visited = 0;
}*/

/*void	ft_find_shortest(t_map *nest, int start, int prev)
{
	int 	cur;
	t_room	*rooms;
	int 	i;
	int 	j;

	i = -1;
	rooms = nest->rooms;
	while (++i < nest->num_of_rooms)
	{
		if (prev >= 0)
			rooms[prev].visited = 1;
		if (!rooms[rooms[cur].links[i]].visited)
		{
			j = -1;
			while (++j < rooms[cur].num_of_links)
			{
				if (i == 0)
					cur = start;
				else
					cur = rooms[cur].links[i];
				if (!rooms[rooms[cur].links[j]].visited && (!rooms[rooms[cur].links[j]].weght || rooms[rooms[cur].links[j]].weght > 1 + rooms[cur].weght))
					rooms[rooms[cur].links[j]].weght = 1 + rooms[cur].weght;
			}
		}
		if (prev >= 0)
			rooms[prev].visited = 0;
	}
}
*/

int		ft_room_less_weght(t_map *nest)
{
	int i;
	int cur_weght;
	int less;
	int index;

	index = -1;
	less = 2147483645;
	i = -1;
	while (++i < nest->num_of_rooms)
	{
		cur_weght =  nest->rooms[i].weght;
		if (!nest->rooms[i].forbbiden && (nest->rooms[i].open || nest->rooms[i].start) && cur_weght < less)
		{
			if (nest->rooms[i].start)
				nest->rooms[i].forbbiden = 1;
			less = cur_weght;
			index = i;
		}
	}
	return (index);
}


void ft_check_next_rooms(t_map *nest, int current)
{
	int i;
	int tmp;

	i = -1;
	while (++i < nest->rooms[current].num_of_links)
	{
		if (nest->rooms[nest->rooms[current].links[i]].forbbiden)
			continue ;
		tmp = nest->rooms[current].weght + 1;
		if (tmp < nest->rooms[(nest->rooms[current].links[i])].weght)
			nest->rooms[(nest->rooms[current].links[i])].weght = tmp;
		nest->rooms[nest->rooms[current].links[i]].open = 1;
	}
	//nest->rooms[less_next].visited = 1;
	nest->rooms[current].forbbiden = 1;
}

//void	ft_make_open(t_map *nest)
//{
//	int i;
//	int j;
//
//	i = -1;
//	j = -1;
//	while (++i < nest->num_of_rooms)
//	{
//		if (nest->rooms[i].open == 1)
//			return;
//	}
//	i = -1;
//	while (++i < nest->num_of_rooms)
//	{
//		if (nest->rooms[i].forbbiden)
//		{
//			while (++j < nest->rooms[i].num_of_links)
//			{
//				nest->rooms[nest->rooms[i].links[j]].open = 1; // получить ссылки запрещенной комнаты на следующие
//			}
//		}
//	}
//}

void	ft_find_shortest(t_map *nest, int cur)
{
	int i;
	int less_next;

	i = -1;
	nest->rooms[cur].visited = 1;
	ft_initialis_weight(nest);
	while (++i < nest->num_of_rooms)
	{
		if (nest->rooms[i].end)
			nest->rooms->index_end = i;
		if ((less_next = ft_room_less_weght(nest)) == -1)
			exit (1);
		ft_check_next_rooms(nest, less_next);
		//nest->rooms[i].forbbiden = 1;
	}
	if (!nest->rooms[nest->rooms->index_end].weght)
		exit (1);  // наверное надо тсначала нормально чистить
	/*while (++j < nest->num_of_rooms)
	{
		while (++i < nest->rooms[cur].num_of_links)
		{
			nest->rooms[nest->rooms[cur].links[i]].weght += 1;
			if (i == nest->rooms[cur2].num_of_links)
				cur2 = cur;
		}
		while (!nest->rooms[++i].end) {

		}
	}*/
}

void ft_write_ways(t_map *nest,	int j,	int i)  // здесь ошибка не выводит файл мап, разложи на бумаге
{
	int	end;
	int cur;
	int prev;

	end = ft_found_end(nest);
	cur = end;
	while (++i <= nest->rooms[end].weght)
	{
		j = -1;
		while (++j < nest->rooms[cur].num_of_links)
		{
			prev = nest->rooms[cur].links[j];
			if (nest->rooms[cur].weght - 1 == nest->rooms[prev].weght)
			{
				nest->ways[ft_find_index_ways(nest, cur, nest->rooms[cur].links[j])].shortest = 1;
				cur = nest->rooms[cur].links[j];
				j = -1;
			}
		}
	}
}

void	ft_write_shortest(t_map *nest)
{
	int		cur;
	int 	i;
	int 	j;
	int		end;

	i = -1;
	end = ft_found_end(nest);
	cur = ft_found_start(nest);
	j = -1;
	while (++j < nest->rooms[cur].num_of_links)
	{
		if (nest->rooms[cur].weght < nest->rooms[nest->rooms[cur].links[j]].weght
		&& nest->ways[ft_find_index_ways(nest, cur, nest->rooms[cur].links[j])].shortest)
		{
			printf("***%s --- %s***\n", nest->rooms[cur].name, nest->rooms[nest->rooms[cur].links[j]].name);
			/*ft_putstr(nest->rooms[cur].name);
			ft_putstr(" --- ");
			ft_putstr(nest->rooms[nest->rooms[cur].links[j]].name);
			ft_putchar('\n');*/
			cur = nest->rooms[cur].links[j];
			j = -1;
			if (cur == end)
				return;
		}
	}
}

void	ft_solution(t_map *nest)
{
	int		start;
	int		less_follow;
	int 	i;

	i = -1;
	start = ft_found_start(nest);
	ft_find_shortest(nest, start);
	ft_write_ways(nest, -1, -1);
	ft_write_shortest(nest);
}

void main_solution(t_map *nest)
{
	ft_malloc_and_fill__ways(nest);
	ft_solution(nest);
	//show_map(nest);
}