#include "../lem_in.h"

void ft_clear_piece_of_path(t_map *nest, int point_inters, int start, int i)
{
	while (++i < nest->rooms[start].num_of_links)
	{
		if (nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1 &&
		(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib)
		&& !nest->rooms[nest->rooms[start].links[i]].hide)
		{
			nest->rooms[start].sh = 0;
			nest->rooms[nest->rooms[start].links[i]].sh = 0;
			nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[i])].shortest = 0; // удаляем трубку
			start = nest->rooms[start].links[i];
			i = -1;
		}
	}
}

int 	ft_find_new_path(t_map *nest, int i, int start, int *count_path)
{
	int tmp;

	tmp = start;
	while (++i < nest->rooms[start].num_of_links)
	{
		if ((nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1) &&
				(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib)
				&& !nest->rooms[nest->rooms[start].links[i]].sh && !nest->rooms[nest->rooms[start].links[i]].hide)
		{
			nest->ways[ft_find_index_ways(nest, start, nest->rooms[start].links[i])].shortest = *count_path; // сохраняем трубку, но если встретим пересечение надо либо удалять либо потом начинать отсюда
			if (!nest->rooms[start].start)
				nest->rooms[start].sh = *count_path;
			if (!nest->rooms[nest->rooms[start].links[i]].end)
				nest->rooms[nest->rooms[start].links[i]].sh = *count_path;
			start = nest->rooms[start].links[i];
			i = -1;
		}
		else if (nest->rooms[nest->rooms[start].links[i]].end)
		{
			(*count_path)++;
			return (-1);
		}
		else if (nest->rooms[nest->rooms[start].links[i]].weght != nest->rooms[start].weght + 1 &&
				 nest->rooms[nest->rooms[start].links[i]].forb_new_way &&
				 !nest->rooms[nest->rooms[start].links[i]].invisib && !nest->rooms[nest->rooms[start].links[i]].start)
		{
			ft_clear_piece_of_path(nest, nest->rooms[start].links[i], tmp, -1);
			return (nest->rooms[start].links[i]);
		}
	}

	return (-1);
}

void ft_remove_weight(t_map *nest, int i)
{
	while (++i < nest->num_of_rooms)
	{
		nest->rooms[i].weght = 0;
		nest->rooms[i].sh = 0;
		nest->rooms[i].forb_new_way = 0;
		nest->rooms[i].forbbiden = 0;
	}
}

int    is_free_way(t_map *nest, int start, int i)
{
   while (++i < nest->rooms[start].num_of_links)
   {

   }
   return 1;
}

void	ft_find_new_paths(t_map *nest, int count_path) // если количество путей 1, надо искать 2 и тд
{
	int index_forb;
	int i;

	i = -1;
	while (!is_free_way(nest, nest->index_start, -1) && (index_forb = ft_find_new_path(nest, -1, nest->index_start, &count_path)) != -1) // но надо тут менять, чтобы не искал forbbiden
	{
		find_sets(nest);
		// вернул не -1 значит путь не найден, а найдена вершина пересечения с запрещенной линией
		//index_forb - вершина пересечения нового пути и запрещенного пути
		// пускаю в бой ft_line_breaker();
		ft_line_breaker(nest, index_forb);
		// обрезано пересечение, надо обнулить веса и форб иначе не получится найти путь
		ft_remove_weight(nest, -1);
		ft_find_shortest(nest, -1);
	}
	if (nest->rooms[nest->index_start].num_of_links + 1 >= count_path
		&& nest->rooms[nest->index_end].num_of_links + 1 >= count_path)
		ft_find_new_paths(nest, count_path + 1); //  так как нашел путь мы увеличиваем, пока хз как это использовать
	else
		find_sets(nest);
}