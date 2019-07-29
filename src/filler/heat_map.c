#include "filler.h"

void	get_heat_map(t_filler *filler)
{
	int 	y;
	int 	x;

	filler->heat_map = (int **)malloc(sizeof(int *) * (filler->map_size.y));
	y = -1;
	while (++y < filler->map_size.y)
	{
		filler->heat_map[y] = ft_memalloc(sizeof(int) * (filler->map_size.x));
		x = -1;
		while(++x < filler->map_size.x)
			filler->heat_map[y][x] = 999;
	}
	//if surrounded -> 0,0

	//start with middle
	// after meet
	if (!is_meet(filler))
		heat_map_maker(filler, filler->map_size.x / 2, filler->map_size.y / 2, 0);
	else
	{
		y = -1;
		while (++y < filler->map_size.y)
		{
			x = -1;
			while(++x < filler->map_size.x)
				if (ft_strchr(filler->p2, filler->map[y][x]))
					heat_map_maker(filler, x, y, 0);
		}
	}
}

void	heat_map_maker(t_filler *filler, int x, int y, int from)
{
	int		**tab;
	t_cor	size;

	if (x < 0 || x > filler->map_size.x || y < 0 ||
		y > filler->map_size.y || ft_strchr(filler->p1, filler->map[y][x]))
		return ;
	tab = filler->heat_map;
	size = filler->map_size;
	if (from <= tab[y][x])
		tab[y][x] = from++;
	if (x - 1 >= 0 && (tab[y][x - 1] == 0 || tab[y][x - 1] > from)
		&& !ft_strchr(filler->p2, filler->map[y][x - 1]))
		heat_map_maker(filler, x - 1, y, from);
	if (x + 1 < size.x && (tab[y][x + 1] == 0 || tab[y][x + 1] > from)
	 	&& !ft_strchr(filler->p2, filler->map[y][x + 1]))
		heat_map_maker(filler, x + 1, y, from);
	if (y - 1 >= 0 && (tab[y - 1][x] == 0 || tab[y - 1][x] > from)
	 	&& !ft_strchr(filler->p2, filler->map[y - 1][x]))
		heat_map_maker(filler, x, y - 1, from);
	if (y + 1 < size.y && (tab[y + 1][x] == 0 || tab[y + 1][x] > from)
		&& !ft_strchr(filler->p2, filler->map[y + 1][x]))
		heat_map_maker(filler, x, y + 1, from);
}

// 다른 x가 있을때, 아래에서 위로 보냈는데, 위에가 엑스이면, 위에서 아래로 또 내려보넴, 지나간 놈은 체크해야할듯
int		is_meet(t_filler *filler)
{
	int		ix;
	int		iy;
	t_cor	size;
	char	**map;

	size = filler->map_size;
	map = filler->map;
	iy = -1;
	while (++iy < size.y)
	{
		ix = -1;
		while (++ix < size.x)
		{
			if(ft_strchr(filler->p1, map[iy][ix]) ||
			((ix - 1 >= 0 && ft_strchr(filler->p2, map[iy][ix - 1])) ||
			(ix + 1 < size.x && ft_strchr(filler->p2, map[iy][ix + 1])) ||
			(iy - 1 >= 0 && ft_strchr(filler->p2, map[iy - 1][ix])) ||
			(iy + 1 < size.y && ft_strchr(filler->p2, map[iy + 1][ix]))))
			return (1);
		}
	}
	return (0);
}
