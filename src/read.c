#include "filler.h"

void	get_data(t_filler *filler)
{
	char	*line;

	line = NULL;
	while (gnl_linked_lst(STDIN_FILENO, &line) > 0)
	{
		if (strstr(line, "Plateau"))
		{
			get_info_of(&(filler->map_size), line);
			get_current_map(filler, filler->map_size.y + 1);
		}
		else if (strstr(line, "Piece"))
		{
			get_info_of(&(filler->piece_size), line);
			get_current_piece(filler, filler->piece_size.y);
			break;
		}
		ft_strdel(&line);
	}
}

int	get_player_info(t_filler *filler)
{
	static int	nb_of_p = 0;
	char		**arr;
	char		*line;

	line = NULL;
	arr = NULL;
	if (nb_of_p)
		exit_on_error("player info");
	if (gnl_linked_lst(0, &line) > 0 && strstr(line, "$$$ exec"))
	{
		arr = ft_strsplit(line, ' ');
		ft_strdel(&line);
	}
	if (strcmp(arr[0], "$$$") || strcmp(arr[1], "exec") || strcmp(arr[3], ":"))
		exit_on_error("player info");
	if (!strcmp(arr[2], "p1"))
	{
		filler->p1 = 'O';
		filler->p2 = 'X';
	}
	nb_of_p += 1;
	free_char_pp(arr);
	return (0);
}

int get_info_of(t_cor *size, char *line)
{
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		exit_on_error("getting info");
	tmp = ft_strtrim_by(line, ':');
	arr = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	size->y = ft_atoi(arr[1]);
	size->x = ft_atoi(arr[2]);
	if (size->y <= 0 || size->x <= 0 ||
		(int)ft_strlen(arr[1]) != ft_numlen(size->x, 10) ||
		(int)ft_strlen(arr[2]) != ft_numlen(size->y, 10))
		exit_on_error("getting info");
	free_char_pp(arr);
	return (0);
}

int	get_current_map(t_filler *filler, int lines)
{
	char	*tmp;
	int		line;

	line = -1;
	tmp = NULL;
	filler->map = (char **)malloc(sizeof(char *) * lines);
	filler->map[lines - 1] = NULL;
	while (++line < lines && gnl_linked_lst(STDIN_FILENO, &tmp) > 0)
	{
		if (line != 0)
			filler->map[line - 1] = ft_strdup(tmp + 4);
		ft_strdel(&tmp);
	}
	return (0);
}

int	get_current_piece(t_filler *filler, int lines)
{
	char	*tmp;
	int		line;

	FILE *f;
	f = fopen("./error","w");

	line = -1;
	tmp = NULL;
	filler->piece = (char **)malloc(sizeof(char *) * (lines + 1));
	filler->piece[lines] = NULL;
	while (++line < lines && gnl_linked_lst(STDIN_FILENO, &tmp) > 0)
	{
		filler->piece[line] = ft_strdup(tmp);
		fprintf(f,"[%d] \t%s\n", line, tmp);
		ft_strdel(&tmp);
		if (line == lines - 1)
			break;
	}

	fprintf(f,"read all!\n");
	fclose(f);

	return (0);
}



// int	get_map_info(t_filler *filler, char *line)
// {
// 	char	**arr;
// 	char	*tmp;

// 	if (ft_c_cnt(line, ' ') != 2)
// 		exit_on_error("map info");
// 	tmp = ft_strtrim_by(line, ':');
// 	arr = ft_strsplit(tmp, ' ');
// 	ft_strdel(&tmp);
// 	filler->map_size.y = ft_atoi(arr[1]);
// 	filler->map_size.x = ft_atoi(arr[2]);
// 	if (filler->map_size.y <= 0 || filler->map_size.x <= 0)
// 		exit_on_error("map info");
// 	free_char_pp(arr);
// 	get_current_map(filler, filler->map_size.y + 1);
// 	return (0);

// }
// int	get_piece_info(t_filler *filler, char *line)
// {
// 	char	**arr;
// 	char	*tmp;

// 	if (ft_c_cnt(line, ' ') != 2)
// 		exit_on_error("piece info");
// 	tmp = ft_strtrim_by(line, ':');
// 	arr = ft_strsplit(tmp, ' ');
// 	ft_strdel(&tmp);
// 	filler->piece_size.y = ft_atoi(arr[1]);
// 	filler->piece_size.x = ft_atoi(arr[2]);
// 	if (filler->piece_size.y <= 0 || filler->piece_size.x <= 0)
// 		exit_on_error("piece info");
// 	free_char_pp(arr);
// 	get_current_piece(filler, filler->piece_size.y);
// 	return (0);
// }

// int get_data_of(char *"getting info", t_filler *filler, int lines)
// {
// 	char	*tmp;
// 	char	*res;

// 	FILE *f;
// 	f = fopen("./error","w");

// 	fprintf(f,"is this working?\n");
// 	tmp = NULL;
// 	while (lines-- && gnl_linked_lst(STDIN_FILENO, &tmp) > 0)
// 	{
// 		fprintf(f,"[%s\t%d] \t%s\n", "getting info",lines, ft_strsplit(tmp, ' ')[1]);
// 		if (lines == 0)
// 		{
// 			ft_strcmp("getting info", "map") == 0 ? (filler->map = ft_strdup(tmp)) : (filler->piece = ft_strdup(tmp));
// 			// filler->map = ft_strdup(tmp);
// 			ft_strdel(&tmp);
// 			break;
// 		}
// 		ft_strdel(&tmp);
// 	}
// 	fprintf(f,"read all!\n");
// 	fclose(f);
// 	return (0);
// 	res = NULL;
// }
