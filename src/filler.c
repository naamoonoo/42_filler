#include "filler.h"

void			put_piece(t_filler *filler)
{
	FILE *f;
	f = fopen("./trace","w");
	for (int j = 0; filler->map[j]; j++)
		fprintf(f, "%s\n", filler->map[j]);

	get_heat_map(filler);

		for (int y = 0; y < filler->map_size.y - 1; y++)
		{
			for (int x = 0; x < filler->map_size.x - 1; x++)
				fprintf(f, "%d\t", filler->heat_map[y][x]);
			fprintf(f, "\n");
		}

	filler->heat_score = 999;

	get_best_position(filler);
	// free_char_pp(filler->map);
	// free_char_pp(filler->piece);
	// int i = 0;
	// while (i < filler->map_size.y - 1)
	// {
	// 	free(filler->heat_map[i++]);
	// }
	// free(filler->heat_map);
	// free_char_pp(filler->heat_map);
	if (filler->best_pos.x >= 0 && filler->best_pos.y >= 0)
	{
		FP("%d %d\n", filler->best_pos.y, filler->best_pos.x);
		filler->best_pos.y = -1;
		filler->best_pos.x = -1;
	}

	fclose(f);

	// FP("50 50\n");

	// calculate



	// FP("x y\n");
}

void	get_heat_map(t_filler *filler)
{
	int 	y;
	int 	x;
	t_cor	loc;

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
			// 	filler->best_pos.x = x;
			// 	filler->best_pos.y = y;
			// }
			if (ft_strchr("xX", filler->map[y][x]))
			{
				loc.x = x;
				loc.y = y;
			}
			filler->heat_map[y][x] = 999;
		}
	}
	heat_map_maker(filler, loc.x, loc.y, 0);
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

void	get_best_position(t_filler *filler)
{
	int x;
	int y;

	FILE *f;
	f = fopen("./get_best_position","w");

	fprintf(f, "update map start\n");
	y = -1;
	while (++y < filler->map_size.y - 1)
	{
		x = -1;
		while (++x < filler->map_size.x - 1)
		{
			update_position(filler, x, y);
			fprintf(f, "[%d, %d]heat score : %d\n", x, y, filler->heat_score);
		}
	}
	fclose(f);
}

void	update_position(t_filler *filler, int x, int y)
{
	int	ix;
	int	iy;

	iy = -1;


		FILE *f;
	f = fopen("./update","w");

	fprintf(f, "update map start\n");



	while (++iy < filler->piece_size.y)
	{
		ix = -1;
		while (++ix < filler->piece_size.x)
		{
			if (iy + y < filler->map_size.y - 1
				&& ix + x < filler->map_size.x - 1
				&& (filler->map[iy + y][ix + x] == 'o'
				|| filler->map[iy + y][ix + x] == 'O'))
				// && iy + y == 8 && ix + x == 2)
				fprintf(f, "piece[%d, %d]\nmap[(%d + %d)%d, (%d + %d)%d] has %c, piece is %c\t heatmap[%d]\n", filler->piece_size.x, filler->piece_size.y, iy, y, y + iy, ix, x, ix + x, filler->map[iy + y][ix + x], filler->piece[iy][ix], filler->heat_map[iy + y][ix + x]);
			if (iy + y < filler->map_size.y - 1
				&& ix + x < filler->map_size.x - 1
				&& ft_strchr("oO", filler->map[iy + y][ix + x])
				&& filler->piece[iy][ix] == '*'
				&& filler->heat_map[iy + y][ix + x] != 0
				&& filler->heat_map[iy + y][ix + x] < filler->heat_score)
			{
				filler->heat_score = filler->heat_map[iy + y][ix + x];
				filler->best_pos.x = x;
				filler->best_pos.y = y;
				fprintf(f, "[%d, %d]heat score : %d\n", x, y, filler->heat_score);
			}
		}
	}
	fclose(f);
}

