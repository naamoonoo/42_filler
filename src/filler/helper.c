#include "filler.h"

void	exit_on_error(char *msg)
{

	FILE *f;
	f = fopen("./error","w");

	fprintf(f,"{red}ERROR : %s{eoc}\n", msg);
	fclose(f);
	exit(0);
}
