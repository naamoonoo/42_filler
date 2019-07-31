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

void	event_handler(t_sdl *sdl)
{
	// int r = 0;
	// int g = 0;
	// int b = 0;
	while (sdl->is_running)
	{
		while (SDL_PollEvent(&(sdl->e))) {
			if (sdl->e.type == SDL_QUIT)
			{
				sdl->is_running = 0;
				printf("running is closed\n");
			}
			// else if (sdl->e.type == SDL_MOUSEMOTION)
			// {
			// 	// printf("mouse x = %d\n", sdl->e.motion.x);
			// 	r = sdl->e.motion.x % 256;
			// 	g = sdl->e.motion.y % 256;
			// 	b = (sdl->e.motion.x + sdl->e.motion.y) % 256;
			// 	printf("mouse is moving[%d %d %d]\n",r,g,b);
			// }
			// else if (event.type == SDL_KEYDOWN)
			// {
			// 	printf("keyboard = %d\t%d\n", event.key.windowID, event.key.type);
			// }
		}
			draw_rectangle(sdl);
			// SDL_UpdateWindowSurface(sdl->win);
			SDL_RenderClear(sdl->ren);
			SDL_RenderPresent(sdl->ren);

			// SDL_RenderClear(sdl->ren);
			// SDL_RenderCopy(sdl->ren, sdl->tex, NULL, &dest);

			// // triggers the double buffers
			// // for multiple rendering
			// SDL_RenderPresent(sdl->ren);

			// calculates to 60 fps
			SDL_Delay(1000 / 60);
	}
}

int main()
{
	t_sdl	*sdl = sdl_init();
	(void)sdl;
	event_handler(sdl);
	return (0);
}
