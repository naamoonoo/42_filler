#include "visualizer.h"

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
	sdl->font[0] = TTF_OpenFont("src/visualizer/gameboy.ttf", 80);
	SDL_RenderSetLogicalSize(sdl->ren, sdl->w, sdl->h);
	SDL_SetRenderDrawColor(sdl->ren, 169, 169, 169, 0);
	sdl->is_running = 1;
	sdl->is_quit = 0;
	return (sdl);
}

