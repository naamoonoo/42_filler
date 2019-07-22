#include "filler.h"

int main()
{
	t_filler	*filler;
	char *line;

	FILE *f;
	f = fopen("./trace","w");

	line = NULL;
	filler = ft_memalloc(sizeof(t_filler));
	fprintf(f, "start\n");



	while (get_next_line(STDIN_FILENO, &line) >= 0)
	{
		if (line == NULL)
			continue;
		fprintf(f, "[original] %s\n", line);
		if (strstr(line, "$$$ exec")){
			get_player_info(filler, line);
		} else if (strstr(line, "Plateau")){
			get_map_info(filler, line);
			get_current_map(filler);
			fprintf(f, "read current map finished\n");
			// return(0);
		} else if (strstr(line, "Piece")){
			get_piece_info(filler, line);
			get_current_piece(filler);
		}
		// if (filler->map_size.x)
		// 	break;
		ft_strdel(&line);
	}
	FP("8 2\n");
	fprintf(f, "p1 : %c\t p2 : %c\n", filler->p1, filler->p2);
	fprintf(f, "map size is [%d, %d]\n", filler->map_size.x, filler->map_size.y);
	fprintf(f, "map is %s\n", filler->map);
	fprintf(f,"end\n");
	fclose(f);

	return (0);
}
