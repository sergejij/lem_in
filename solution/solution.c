#include "../lem_in.h"

t_lst	*choose_set(t_lst *lst)
{
	t_lst		*cur;
	t_lst		*tmp;

	tmp = lst;
	cur = lst;
	while (cur)
	{
		if (cur->sum < tmp->sum)
			tmp = cur;
		cur = cur->next;
	}
	return (tmp);
}

void	ft_solution(t_map *nest)
{

	nest->index_start = ft_found_start(nest);
	ft_find_shortest(nest, -1); // тут не должна вернуть -1, так как еще нет forb_new_way
	ft_record_ways(nest, -1, -1, nest->index_end);
	find_sets(nest);
//	ft_write_shortest(nest);
	if (nest->rooms[nest->index_start].num_of_links > 1
		&& nest->rooms[nest->index_end].num_of_links > 1)
	{
		ft_find_new_paths(nest, 2);
	}
//	else
//		ft_use_shortest(nest); // make full solution */
}

void	main_solution(t_map *nest)
{
	//show_map(nest);
	ft_malloc_and_fill_ways(nest);
	ft_solution(nest);
	if (nest->sets)
		print_solution(choose_set(nest->sets), nest);
	ft_show_sets(nest);
//	show_map(nest);
}