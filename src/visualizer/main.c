#include "visualizer.h"

int main()
{
	// t_sdl		*sdl = sdl_init();
	t_filler	*filler = ft_memalloc(sizeof(t_filler));
	init_data(filler);

	SDL_Window	*window;
	SDL_Surface	*screenSurface;

	window = NULL;
	screenSurface = NULL;
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	else
	{
		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
		if( window == NULL )
			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
		else
		{
			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
			//Get window surface
			int is_running = 1;
			int r = 0;
			int g = 0;
			int b = 0;
			SDL_Event event;
			while (is_running) {
				while (SDL_PollEvent(&event)) {
					if (event.type == SDL_QUIT)
					{
						is_running = 0;
						printf("running is closed\n");
					}
					else if (event.type == SDL_MOUSEMOTION)
					{
						printf("mouse x = %d\n", event.motion.x);
						r = event.motion.x % 256;
						g = event.motion.y % 256;
						b = (event.motion.x + event.motion.y) % 256;
						// printf("mouse is moving[%d %d %d]\n",r,g,b);
					}
					else if (event.type == SDL_KEYDOWN)
					{
						printf("keyboard = %d\t%d\n", event.key.windowID, event.key.type);
					}
				}
				SDL_SetRenderDrawColor(renderer, r, g, b, 255);
				SDL_RenderClear(renderer);
				SDL_RenderPresent(renderer);
			}
		}
	}
	SDL_DestroyWindow( window );

	SDL_Quit();

	SDL_Init(SDL_INIT_VIDEO);
	return (0);
}
