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
			// get_info_of(&(filler->map_size), line);

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

void draw_rectangle(t_sdl *sdl)
{
	// Set render color to red ( background will be rendered in this color )
	// Creat a rect at pos ( 50, 50 ) that's 50 pixels wide and 50 pixels high.
	SDL_Rect r;
	r.x = 50;
	r.y = 50;
	r.w = 50;
	r.h = 50;

	// Set render color to blue ( rect will be rendered in this color )
	SDL_SetRenderDrawColor( sdl->ren, 0, 0, 255, 255 );

	// Render rect
	SDL_RenderFillRect( sdl->ren, &r );

	// Render the rect to the screen
	// SDL_RenderPresent(sdl->ren);
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
	// SDL_RenderClear(sdl->ren);
	// SDL_RenderPresent(sdl->ren);
	sdl->is_running = 1;
	return (sdl);
}

