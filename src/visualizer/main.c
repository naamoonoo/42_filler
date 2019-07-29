#include "visualizer.h"
#include "filler.h"

int main()
{
	// t_sdl		*sdl = sdl_init();
	// t_filler	*filler = ft_memalloc(sizeof(t_filler));
	char *line = NULL;
	while (gnl_linked_lst(0, &line) > 0)
	{
		printf("%s\n", line);
		if (ft_strstr(line, "<got (O)"))
			break;
	}
	// SDL_Window	*window;
	// SDL_Surface	*screenSurface;

	// (void)sdl;
	// window = NULL;
	// screenSurface = NULL;
	// if (SDL_Init(SDL_INIT_VIDEO) < 0)
	// 	printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
	// else
	// {
	// 	window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN );
	// 	if( window == NULL )
	// 		printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
	// 	else
	// 	{
	// 		SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	// 		//Get window surface
			// int r = 0;
			// int g = 0;
			// int b = 0;
			// SDL_Event event;
			// while (sdl->is_running) {
			// 	while (SDL_PollEvent(&event)) {
			// 		if (event.type == SDL_QUIT)
			// 		{
			// 			sdl->is_running = 0;
			// 			printf("sdl->running is closed\n");
			// 		}
			// 		else if (event.type == SDL_MOUSEMOTION)
			// 		{
			// 			printf("mouse x = %d\n", event.motion.x);
			// 			r = event.motion.x % 256;
			// 			g = event.motion.y % 256;
			// 			b = (event.motion.x + event.motion.y) % 256;
			// 			// printf("mouse is moving[%d %d %d]\n",r,g,b);
			// 		}
			// 		else if (event.type == SDL_KEYDOWN)
			// 		{
			// 			printf("keyboard = %d\t%d\n", event.key.windowID, event.key.type);
			// 		}
			// 	}
			// 	SDL_SetRenderDrawColor(sdl->renderer, r, g, b, 255);
			// 	SDL_RenderClear(sdl->renderer);
			// 	SDL_RenderPresent(sdl->renderer);
			// }
	// 	}
	// }
	// SDL_DestroyWindow( window );

	//Quit SDL subsystems
	// SDL_Quit();

	// SDL_Init(SDL_INIT_VIDEO);
	return (0);
}
