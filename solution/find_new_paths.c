#include "../lem_in.h"

void ft_clear_piece_of_path(t_map *nest, int point_inters, int start, int i)
{
	while (++i < nest->rooms[start].num_of_links)
	{
		if (nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1 &&
		(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib))
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
		if ((nest->rooms[nest->rooms[start].links[i]].weght == nest->rooms[start].weght + 1 /*|| nest->rooms[nest->rooms[start].links[i]].invisib*/) &&
				(!nest->rooms[nest->rooms[start].links[i]].forb_new_way || nest->rooms[nest->rooms[start].links[i]].invisib)
				&& !nest->rooms[nest->rooms[start].links[i]].sh) // косяк с условием прыгает на way[2] - 1-4
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
			// нужно сохранить этот путь
			// мы не нашли пересечения с форб, а нашли новый путь
		}
		else if (nest->rooms[nest->rooms[start].links[i]].weght != nest->rooms[start].weght + 1 &&
				 nest->rooms[nest->rooms[start].links[i]].forb_new_way &&
				 !nest->rooms[nest->rooms[start].links[i]].invisib && !nest->rooms[nest->rooms[start].links[i]].start)
		{
			// надо записывать сразу путь
			// а если оказался тут надо его очистить
			ft_clear_piece_of_path(nest, nest->rooms[start].links[i], tmp, -1);
			return (nest->rooms[start].links[i]);
		}
	}
	return (-1);
}

void ft_remove_weight(t_map *nest, int i)
{
	while (++i <= nest->num_of_rooms)
	{
		nest->rooms[i].weght = 0;
		nest->rooms[i].sh = 0;
		nest->rooms[i].forb_new_way = 0;
		nest->rooms[i].forbbiden = 0;
	}
}

void	ft_find_new_paths(t_map *nest, int count_path) // если количество путей 1, надо искать 2 и тд
{
	int index_forb;
	/*int i;

	i = -1;
	while (++i < nest->num_of_ways)
	{
		if (nest->ways[i].shortest)
			nest->ways[i].forbbiden;
	} попробую без доп флага, там еще невидимый будет*/
	int i;

	i = -1;
	/*while (++i < nest->num_of_rooms)
	{
		if (nest->rooms[i].forbbiden)
			nest->rooms[i].forbbiden = 0;
	}*/


	/*
	 *
	 * тут сега, надо правильно выделять память на это всё и не потеряться
	 *
	 */

	/*if(!(nest->sets = ft_memalloc(sizeof(t_way) * nest->num_of_ways)))
		exit(1);
	nest->sets[count_path].v = (int**)malloc(sizeof(int*) * count_path);
	ft_record_sets(nest, count_path - 1, -1);*/

	while ((index_forb = ft_find_new_path(nest, -1, nest->index_start, &count_path)) != -1) // но надо тут менять, чтобы не искал forbbiden
	{
		find_sets(nest);
		ft_show_sets(nest);
		// вернул не -1 значит путь не найден, а найдена вершина пересечения с запрещенной линией
		//index_forb - вершина пересечения нового пути и запрещенного пути
		// пускаю в бой ft_line_breaker();
		ft_line_breaker(nest, index_forb);
		// обрезано пересечение, надо обнулить веса и форб иначе не получится найти путь
		ft_remove_weight(nest, -1);
		ft_find_shortest(nest, -1);
	}
		/*
		 *
		 *
		 * Тут надо вызвать функцию, которая будет создавать сеты. Сначала запишет шортест = 1, но 1 надо записать сверху. Затем Шортест 2 - 3.
		 * Но как-то надо понять сколько путей и под какими цифрами нужно записать в данной операции.
		 * Сколько путей это просто, если для этого count_path
		 * А под какими номерами, надо смотреть на тот предыдущий номер который записали
		 *
		 *
		 */
	if (nest->rooms[nest->index_start].num_of_links >= count_path
		&& nest->rooms[nest->index_end].num_of_links >= count_path)
		ft_find_new_paths(nest, count_path + 1); //  так как нашел путь мы увеличиваем, пока хз как это использовать
	else
	{
		find_sets(nest);
		ft_show_sets(nest);
	}
		// но надо каждый раз искать на 1 путь больше чем в предыдущий
	// и возвращаял индекс вершины в которой есть пересечение с шортест/форбиден
}