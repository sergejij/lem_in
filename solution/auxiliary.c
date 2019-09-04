#include "lem_in.h"

int		ft_found_start(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_rooms)
		if (nest->rooms[i].start)
			return (i);
	return (-1);
}

void	ft_write_shortest(t_map *nest)
{
	int		cur;
	int 	j;
	int		end;

	end = nest->index_end;
	cur = nest->index_start;
	j = -1;
	while (++j < nest->rooms[cur].num_of_links)
	{
		if (nest->rooms[cur].weght < nest->rooms[nest->rooms[cur].links[j]].weght
			&& nest->ways[ft_find_index_ways(nest, cur, nest->rooms[cur].links[j])].shortest == 1)
		{
			printf("***%s --- %s***\n", nest->rooms[cur].name, nest->rooms[nest->rooms[cur].links[j]].name);
			cur = nest->rooms[cur].links[j];
			j = -1;
			if (cur == end)
				return;
		}
	}
}
