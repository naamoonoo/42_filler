#include "filler.h"

int main()
{
	t_filler	*filler;
	char *line;

	line = NULL;
	filler = ft_memalloc(sizeof(t_filler));
	if (!filler->p1)
		get_player_info(filler);
	int i = 0;
	i++;
	FILE *f = fopen("./res", "w");

	while (1)
	{
		get_data(filler);
	// filler->map[11][14] = 'X';
	// filler->map[10][14] = 'X';
		put_piece(filler);


		// if (++i == 15)
		// {
		// 	fprintf(f, "%d %d\n", filler->best_pos.y, filler->best_pos.x);
		// 	break ;
		// }
		// continue ;
		// for (int y = 0; y < filler->map_size.y - 1; y++)
		// {
		// 	for (int x = 0; x < filler->map_size.x - 1; x++)
		// 		fprintf(f, "%d\t", filler->heat_map[y][x]);
		// 	fprintf(f, "\n");
		// }
		// int i = 0;
		// while (i < filler->map_size.y - 1)
		// {
		// 	free(filler->heat_map[i++]);
		// }
		// free(filler->heat_map);
		// break;
	}
	fclose(f);
	// while (1)
	// 	sleep(1);
	// if (get_data(filler) == 1)
	// 	return (1);
	// FP("8 2\n");

	// fprintf(f, "p1 : %c\t p2 : %c\n", filler->p1, filler->p2);
	// fprintf(f, "map size is [%d, %d]\n", filler->map_size.x, filler->map_size.y);
	// // for (int j = 0; j < filler->map_size.y; j++)
	// // fprintf(f, "map %s\n", filler->map[1]);
	// // fprintf(f, "map %s\n", filler->map[2]);
	// fprintf(f, "piece size is [%d, %d]\n", filler->piece_size.x, filler->piece_size.y);
	// for (int j = 0; filler->piece[j]; j++)
	// 	fprintf(f, "piece %s\n", filler->piece[j]);
	// // for (int j = 0; j < filler->piece_size.y; j++)
	// // fprintf(f, "piece %s\n", filler->piece);
	// // fprintf(f, "piece %s\n", filler->piece[0]);
	// fprintf(f,"end\n");

	return (0);
}
