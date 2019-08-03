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

void	event_handler(t_sdl *sdl, t_f *filler)
{

	// int r = 0;
	// int g = 0;
	// int b = 0;
	(void)filler;
	while (sdl->is_running)
	{
		while (SDL_PollEvent(&(sdl->e))) {
			if (sdl->e.type == SDL_QUIT)
			{
				sdl->is_running = 0;
				printf("running is closed\n");
			}
		}
			SDL_RenderClear(sdl->ren);
			draw_map(sdl, filler);
			SDL_SetRenderDrawColor(sdl->ren, 0xdc, 0xdd, 0Xe1, 0);
			SDL_RenderPresent(sdl->ren);

                // SDL_RenderClear( gRenderer );

                // //Render texture to screen
                // SDL_RenderCopy( gRenderer, gTexture, NULL, NULL );

                // //Update screen
                // SDL_RenderPresent( gRenderer );

			// SDL_RenderClear(sdl->ren);
			// SDL_RenderCopy(sdl->ren, sdl->tex, NULL, &dest);

			// // triggers the double buffers
			// // for multiple rendering
			// SDL_RenderPresent(sdl->ren);

			// calculates to 60 fps
			SDL_Delay(1000 / 60);
	}
}

// void	make_

int main()
{
	t_sdl	*sdl = sdl_init();
	(void)sdl;
	t_f *f = ft_memalloc(sizeof(t_f));
	init_data(f);
	event_handler(sdl, f);
	return (0);
}
