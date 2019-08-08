#include "filler.h"

void	exit_on_error(char *msg)
{

	FILE *f;
	f = fopen("./error","w");

	fprintf(f,"{red}ERROR : %s{eoc}\n", msg);
	fclose(f);
	exit(0);
}

void	free_heat_map(t_filler *f)
{
	int	y;

	y = -1;
	while (++y < f->map_size.y)
		free(f->heat_map[y]);
	free(f->heat_map);
}
