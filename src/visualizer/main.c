#include "visualizer.h"


#define WINDOW_WIDTH 300
#define WINDOW_HEIGHT (WINDOW_WIDTH)

// /*
// - x, y: upper left corner.
// - texture, rect: outputs.
// */
// // void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
// //         TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
// //     int text_width;
// //     int text_height;
// //     SDL_Surface *surface;
// //     SDL_Color textColor = {255, 255, 255, 0};

// //     surface = TTF_RenderText_Solid(font, text, textColor);
// //     *texture = SDL_CreateTextureFromSurface(renderer, surface);
// //     text_width = surface->w;
// //     text_height = surface->h;
// //     SDL_FreeSurface(surface);
// //     rect->x = x;
// //     rect->y = y;
// //     rect->w = text_width;
// //     rect->h = text_height;
// // }

// // int main(int argc, char **argv) {
// //     SDL_Event event;
// //     SDL_Rect rect1, rect2;
// //     SDL_Renderer *renderer;
// //     SDL_Texture *texture1, *texture2;
// //     SDL_Window *window;
// //     char *font_path;
// //     int quit;

// //     if (argc == 1) {
// //         font_path = "src/visualizer/FreeSans.ttf";
// //     } else if (argc == 2) {
// //         font_path = argv[1];
// //     } else {
// //         fprintf(stderr, "error: too many arguments\n");
// //         exit(EXIT_FAILURE);
// //     }

// //     /* Inint TTF. */
// //     SDL_Init(SDL_INIT_TIMER | SDL_INIT_VIDEO);
// //     SDL_CreateWindowAndRenderer(WINDOW_WIDTH, WINDOW_WIDTH, 0, &window, &renderer);
// //     TTF_Init();
// //     TTF_Font *font = TTF_OpenFont(font_path, 24);
// //     if (font == NULL) {
// //         fprintf(stderr, "error: font not found\n");
// //         exit(EXIT_FAILURE);
// //     }
// //     get_text_and_rect(renderer, 0, 0, "hnam", font, &texture1, &rect1);
// //     get_text_and_rect(renderer, 0, rect1.y + rect1.h, "filler", font, &texture2, &rect2);

// //     quit = 0;
// //     while (!quit) {
// //         while (SDL_PollEvent(&event) == 1) {
// //             if (event.type == SDL_QUIT) {
// //                 quit = 1;
// //             }
// //         }
// //         SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
// //         SDL_RenderClear(renderer);

// //         /* Use TTF textures. */
// //         SDL_RenderCopy(renderer, texture1, NULL, &rect1);
// //         SDL_RenderCopy(renderer, texture2, NULL, &rect2);

// //         SDL_RenderPresent(renderer);
// //     }

// //     /* Deinit TTF. */
// //     SDL_DestroyTexture(texture1);
// //     SDL_DestroyTexture(texture2);
// //     TTF_Quit();

// //     SDL_DestroyRenderer(renderer);
// //     SDL_DestroyWindow(window);
// //     SDL_Quit();
// //     return EXIT_SUCCESS;
// // }

// void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
//         TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
//     int text_width;
//     int text_height;
//     SDL_Surface *surface;
//     SDL_Color textColor = {255, 255, 255, 0};
//     surface = TTF_RenderText_Solid(font, text, textColor);
//     *texture = SDL_CreateTextureFromSurface(renderer, surface);
//     text_width = surface->w;
//     text_height = surface->h;
//     SDL_FreeSurface(surface);
//     rect->x = x;
//     rect->y = y;
//     rect->w = text_width;
//     rect->h = text_height;
// 	printf("%s is rendered\n", text);
// }

// int main()
// {
// 	// t_sdl		*sdl = sdl_init();
// 	t_filler	*filler = ft_memalloc(sizeof(t_filler));
// 	init_data(filler);

// 	SDL_Window	*window;
// 	SDL_Surface	*screenSurface;

// 	window = NULL;
// 	screenSurface = NULL;

// 	if (SDL_Init(SDL_INIT_VIDEO) < 0)
// 		printf("SDL could not initialize! SDL_Error: %s\n", SDL_GetError());
// 	else
// 	{
// 		window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN );
// 		if( window == NULL )
// 			printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
// 		else
// 		{
// 			SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
// 			//Get window surface
// 			SDL_Rect rect1;
// 			SDL_Texture *texture1;
// 			TTF_Init();
// 			TTF_Font *font = TTF_OpenFont("src/visualizer/FreeSans.ttf", 24);
// 			if (font == NULL) {
// 				fprintf(stderr, "error: font not found\n");
// 				exit(EXIT_FAILURE);
// 			}
// 			get_text_and_rect(renderer, 10, 10, "hello", font, &texture1, &rect1);
// 			int is_running = 1;
// 			int r = 0;
// 			int g = 0;
// 			int b = 0;
// 			SDL_Event event;
// 			while (is_running) {
// 				while (SDL_PollEvent(&event)) {
// 					if (event.type == SDL_QUIT)
// 					{
// 						is_running = 0;
// 						printf("running is closed\n");
// 					}
// 					// else if (event.type == SDL_MOUSEMOTION)
// 					// {
// 					// 	printf("mouse x = %d\n", event.motion.x);
// 					// 	// r = event.motion.x % 256;
// 					// 	// g = event.motion.y % 256;
// 					// 	// b = (event.motion.x + event.motion.y) % 256;
// 					// 	// printf("mouse is moving[%d %d %d]\n",r,g,b);
// 					// }
// 					// else if (event.type == SDL_KEYDOWN)
// 					// {
// 					// 	printf("keyboard = %d\t%d\n", event.key.windowID, event.key.type);
// 					// }
// 				}
// 				SDL_RenderCopy(renderer, texture1, NULL, &rect1);
// 				SDL_SetRenderDrawColor(renderer, r, g, b, 255);
// 				SDL_RenderClear(renderer);
// 				SDL_RenderPresent(renderer);
// 			}
// 		}
// 	}
// 	SDL_DestroyWindow( window );

// 	SDL_Quit();

// 	SDL_Init(SDL_INIT_VIDEO);
// 	return (0);
// }
