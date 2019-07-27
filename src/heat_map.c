#include "filler.h"

void	get_heat_map(t_filler *filler)
{
	int 	y;
	int 	x;

	filler->heat_map = (int **)malloc(sizeof(int *) * (filler->map_size.y - 1));
	y = -1;
	while (++y < filler->map_size.y - 1)
	{
		x = -1;
		filler->heat_map[y] = ft_memalloc(sizeof(int) * filler->map_size.x - 1);
		while (++x < filler->map_size.x - 1)
		{
			// if (ft_strchr("oO", filler->map[y][x]))
			// {
			// 	filler->p1_pos.x = x;
			// 	filler->p1_pos.y = y;
			// }
			if (ft_strchr("xX", filler->map[y][x]))
			{
				filler->p2_pos.x = x;
				filler->p2_pos.y = y;
			}
			filler->heat_map[y][x] = 999;
		}
	}
	heat_map_maker(filler, filler->p2_pos.x, filler->p2_pos.y, 0);
}

void	heat_map_maker(t_filler *filler, int x, int y, int from)
{
	int		**tab;
	t_cor	size;

	if (x < 0 || x > filler->map_size.x - 1 || y < 0 || y > filler->map_size.y - 1
	|| ft_strchr("oO", filler->map[y][x]) )
		return ;
	tab = filler->heat_map;
	size = filler->map_size;
	if (from <= tab[y][x])
		tab[y][x] = from++;
	if (x - 1 >= 0 && (tab[y][x - 1] == 0 || tab[y][x - 1] > from))
		heat_map_maker(filler, x - 1, y, from);
	if (x + 1 < size.x - 1 && (tab[y][x + 1] == 0 || tab[y][x + 1] > from))
		heat_map_maker(filler, x + 1, y, from);
	if (y - 1 >= 0 && (tab[y - 1][x] == 0 || tab[y - 1][x] > from))
		heat_map_maker(filler, x, y - 1, from);
	if (y + 1 < size.y - 1 && (tab[y + 1][x] == 0 || tab[y + 1][x] > from))
		heat_map_maker(filler, x, y + 1, from);
}

// 다른 x가 있을때, 아래에서 위로 보냈는데, 위에가 엑스이면, 위에서 아래로 또 내려보넴, 지나간 놈은 체크해야할듯
