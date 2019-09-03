#include "lem_in.h"

void 	ft_mark_shortest_forbidden(t_map *nest)
{
	int i;

	i = -1;
	while (++i < nest->num_of_ways)
	{
		if (nest->ways[i].shortest)
			nest->ways[i].forbbiden;
	}
	ft_find_shortest(nest, nest->index_start); // но надо тут менять, чтобы не искал forbbiden
}

void	ft_find_new_paths(t_map *nest)
{
	ft_mark_shortest_forbidden(nest);
}