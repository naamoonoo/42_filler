#include "visualizer.h"

void	init_data(t_f *f)
{
	char	*line = NULL;
	int		fd = open("./trace", O_RDONLY);
	int		round = 0;

	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec"))
			player_info(f, line);
		else if (ft_strstr(line, "Plateau"))
		{
			round == 0 ? info_of(&(f->map_size), line) : 0;
			current_map(f, f->map_size.y + 1, fd);
		}
		if (ft_strstr(line, "<got"))
			if (round++ == 5)
				break;
		free(line);
	}
	// printf("%s\n%s\n", f->p1, f->p2);
	// for (int i = 0; f->m[i]; i++)
	// {
	// 	for (int j = 0; f->m[i][j]; j++)
	// 		printf("%c ", f->m[i][j]);
	// 	printf("\n");
	// }
}

void	player_info(t_f *f, char *line)
{
	char	**arr;
	int		i;
	static	int call = 0;

	if (call++ > 0)
		return ;
	i = 0;
	arr = ft_strsplit(line, '/');
	while (arr[i] && arr[i + 1])
		i++;
	if (ft_strstr(line, "p1"))
		f->p1_name = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
	else if (ft_strstr(line, "p2"))
		f->p2_name = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
	f->p1 = line[10] == '1' ? "oO" : "xX";
	f->p2 = line[10] == '1' ? "xX" : "oO";
	f->c_p1 = (t_cl){0xFC, 0X5c, 0X65, 255}; // #f7b731, #e58e26
	f->c_p2 = (t_cl){0x38, 0x67, 0xd6, 255}; // #38ada9,
	free_char_pp(arr);
}

int info_of(t_cor *size, char *line)
{
	char	**arr;
	char	*tmp;

	if (ft_c_cnt(line, ' ') != 2)
		return(1);
	tmp = ft_strtrim_by(line, ':');
	arr = ft_strsplit(tmp, ' ');
	ft_strdel(&tmp);
	size->y = ft_atoi(arr[1]);
	size->x = ft_atoi(arr[2]);
	free_char_pp(arr);
	return (0);
}
// void draw_map(t_sdl *sdl, t_f *f)

int	current_map(t_f *f, int lines, int fd)
{
	char		*tmp;
	int			line;
	static int	call = 0;

	line = -1;
	tmp = NULL;

	if (call++ == 0)
	{
		f->m = (char **)malloc(sizeof(char *) * lines);
		f->m[lines - 1] = NULL;
	}
	while (++line < lines && get_next_line(fd, &tmp) > 0)
	{
		if (line != 0)
		{
			if (call != 1)
				free(f->m[line - 1]);
			f->m[line - 1] = ft_strdup(tmp + 4);
		}
		ft_strdel(&tmp);
	}
	return (0);
}

t_sdl	*sdl_init()
{
	t_sdl	*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	TTF_Init();
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->w = 1200;
	sdl->h = 800;
	sdl->win = SDL_CreateWindow("filler visualization", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, sdl->w, sdl->h, SDL_WINDOW_RESIZABLE);
	sdl->ren = SDL_CreateRenderer(sdl->win, -1, SDL_RENDERER_ACCELERATED);
	sdl->font = TTF_OpenFont("src/visualizer/FreeSans.ttf", 24);
	SDL_RenderSetLogicalSize(sdl->ren, sdl->w, sdl->h);
	SDL_SetRenderDrawColor(sdl->ren, 169, 169, 169, 0);
	sdl->is_running = 1;
	return (sdl);
}

