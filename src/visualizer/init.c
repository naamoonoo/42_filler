#include "visualizer.h"

void	init_data(t_filler *filler)
{
	char	*line = NULL;
	int		fd = open("./trace", O_RDONLY);
	while (get_next_line(fd, &line) > 0)
	{
		if (ft_strstr(line, "$$$ exec"))
			player_info(filler, line);
		else if (ft_strstr(line, "Plateau"))
		{
			get_info_of(&(filler->map_size), line);

		}
		if (ft_strstr(line, "<got (O)"))
			break;
		free(line);
	}
	printf("%s\n%s\n", filler->p1, filler->p2);
}

void	player_info(t_filler *filler, char *line)
{
	char	**arr;
	int		i;

	i = 0;
	arr = ft_strsplit(line, '/');
	while (arr[i] && arr[i + 1])
		i++;
	if (ft_strstr(line, "p1"))
		filler->p1 = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
	else if (ft_strstr(line, "p2"))
		filler->p2 = ft_strsub(arr[i], 0, ft_strchr_idx(arr[i], '.'));
	free_char_pp(arr);
}

t_sdl	*sdl_init()
{
	t_sdl	*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->win = SDL_CreateWindow("filler", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
	sdl->ren = SDL_CreateRenderer(sdl->win, -1, 0);
	sdl->is_running = 1;
	return (sdl);
}

