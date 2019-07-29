#include "visualizer.h"

t_sdl	*sdl_init()
{
	t_sdl	*sdl;

	sdl = (t_sdl *)malloc(sizeof(t_sdl));
	SDL_Init(SDL_INIT_EVERYTHING);
	sdl->window = SDL_CreateWindow("filler", SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_RESIZABLE);
	sdl->renderer = SDL_CreateRenderer(sdl->window, -1, 0);
	sdl->is_running = 1;
	return (sdl);
}

