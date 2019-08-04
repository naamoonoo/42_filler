#include "visualizer.h"

void	event_handler(t_sdl *sdl, t_f *f)
{
	if (sdl->e.type == SDL_QUIT)
		sdl->is_quit = 1;
	if (sdl->e.type == SDL_QUIT || sdl->e.key.keysym.sym == SDLK_ESCAPE)
		sdl->is_running = 0;
	else if (sdl->e.key.keysym.sym == SDLK_DOWN)
		parse_data(f, sdl);
	else if (sdl->e.key.keysym.sym == SDLK_RIGHT)
		f->auto_fill = 1;
	else if (sdl->e.key.keysym.sym == SDLK_LEFT)
		f->auto_fill = 0;
	else if (sdl->e.key.keysym.sym == SDLK_1)
	{
		f->c_p1 = (SDL_Color){0xf7, 0xb7, 0x31, 255};
		f->c_p2 = (SDL_Color){0x38, 0x67, 0xd6, 255};
	}
	else if (sdl->e.key.keysym.sym == SDLK_2)
	{
		f->c_p1 = (SDL_Color){0xa0, 0x85, 0x5b, 255};
		f->c_p2 = (SDL_Color){0xdd, 0x6b, 0x4d, 255};
	}
	else if (sdl->e.key.keysym.sym == SDLK_3)
	{
		f->c_p1 = (SDL_Color){0x93, 0x70, 0xdb, 255};
		f->c_p2 = (SDL_Color){0x58, 0x93, 0xd4, 255};
	}
}

void	main_loop(t_sdl *sdl, t_f *f)
{
	while (sdl->is_running)
	{
		while (SDL_PollEvent(&(sdl->e)))
			event_handler(sdl, f);
		SDL_RenderClear(sdl->ren);
		render_piece(sdl, f);
		render_text(sdl, f);
		render_map(sdl, f);
		render_status_bar(sdl, f);
		SDL_SetRenderDrawColor(sdl->ren, 0xdc, 0xdd, 0xe1, 0); /* background */
		f->auto_fill ? parse_data(f, sdl) : 0;
		SDL_RenderPresent(sdl->ren);
		SDL_Delay(1000 / 60); /*60 fps */
	}
}

int main(int ac, char *av[])
{
	t_sdl	*sdl;
	t_f		*f;

	if (ac > 2 && FP("can take only one trace, default is [trace]\n"))
		return (0);
	sdl = sdl_init();
	f = ft_memalloc(sizeof(t_f));
	f->fd = open(ac == 1 ? "./trace" : av[1], O_RDONLY);
	parse_data(f, sdl);
	main_loop(sdl, f);
	while (!sdl->is_quit)
	{
		while (SDL_PollEvent(&(sdl->e)))
			if (sdl->e.type == SDL_QUIT || sdl->e.key.keysym.sym == 27)
				sdl->is_quit = 1;
		SDL_Delay(1000);
	}
	SDL_DestroyRenderer(sdl->ren);
	SDL_DestroyWindow(sdl->win);
	return (0);
}
