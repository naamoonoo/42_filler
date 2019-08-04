#include "visualizer.h"

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
		TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
	int text_width;
	int text_height;
	SDL_Surface *surface;
	SDL_Color textColor = {255, 255, 255, 0};

	surface = TTF_RenderText_Solid(font, text, textColor);
	*texture = SDL_CreateTextureFromSurface(renderer, surface);
	text_width = surface->w;
	text_height = surface->h;
	SDL_FreeSurface(surface);
	rect->x = x;
	rect->y = y;
	rect->w = text_width;
	rect->h = text_height;
}

void	main_loop(t_sdl *sdl, t_f *f)
{
	while (sdl->is_running)
	{
		while (SDL_PollEvent(&(sdl->e))) {
			if (sdl->e.type == SDL_QUIT)
			{
				sdl->is_running = 0;
				printf("running is closed\n");
			}
			else if (sdl->e.key.keysym.sym == SDLK_ESCAPE)
				sdl->is_running = 0;
			else if (sdl->e.key.keysym.sym == SDLK_RIGHT)
				parse_data(f);
			else if (sdl->e.key.keysym.sym == SDLK_RETURN)
				f->auto_fill = !f->auto_fill;
		}
		SDL_RenderClear(sdl->ren);
		render_filler_head(sdl);
		render_map(sdl, f);
		render_status_bar(sdl, f);
		SDL_SetRenderDrawColor(sdl->ren, 0xdc, 0xdd, 0Xe1, 0);
		// SDL_RenderCopy(sdl->ren, sdl->tex, NULL, &(SDL_Rect){300, 20, 100, 100});
		SDL_RenderPresent(sdl->ren);
		SDL_Delay(3600 / 60); /*60 fps */
		// if (f->auto_fill)
			parse_data(f);
		// SDL_Delay(1000 / 60);
	}
}

// void	event_handler()
// {

// }

int main()
{
	t_sdl	*sdl = sdl_init();
	(void)sdl;
	t_f *f = ft_memalloc(sizeof(t_f));
	f->fd = open("./trace", O_RDONLY);
	parse_data(f);
	main_loop(sdl, f);
	get_text_and_rect(sdl->ren, 300, 20, "filler by hnam!", sdl->font, &(sdl->tex), &(SDL_Rect){300, 20, 100, 100});
	return (0);
}
