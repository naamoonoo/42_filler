#include "visualizer.h"

void	render_text(t_sdl *sdl, t_f *f)
{
	int	i;
	sdl->rect[0] = (SDL_Rect){50, 20, 400, 100};
	get_text_and_rect("filler", sdl, 0, (SDL_Color){0, 0, 0, 255});
	sdl->rect[1] = (SDL_Rect){700, 40, 20 * ft_strlen(f->p1_name), 30};
	get_text_and_rect(f->p1_name, sdl, 1, f->c_p1);
	sdl->rect[2] = (SDL_Rect){700 + 20 * ft_strlen(f->p1_name),
		40, 20 * ft_numlen(f->s_p1, 10), 30};
	get_text_and_rect(ft_itoa(f->s_p1), sdl, 2, f->c_p1);
	sdl->rect[3] = (SDL_Rect){700, 80, 20 * ft_strlen(f->p2_name), 30};
	get_text_and_rect(f->p2_name, sdl, 3, f->c_p2);
	sdl->rect[4] = (SDL_Rect){700 + 20 * ft_strlen(f->p2_name),
		80, 20 * ft_numlen(f->s_p2, 10), 30};
	get_text_and_rect(ft_itoa(f->s_p2), sdl, 4, f->c_p2);

	sdl->rect[5] = (SDL_Rect){860, BOX_P_Y + 20, 20 * ft_strlen("color : 1"), 20};
	get_text_and_rect("color : 1", sdl, 5, (SDL_Color){0, 0, 0, 255});
	sdl->rect[6] = (SDL_Rect){860, BOX_P_Y + 40, 20 * ft_strlen("color : 2"), 20};
	get_text_and_rect("color : 2", sdl, 6, (SDL_Color){0, 0, 0, 255});
	sdl->rect[7] = (SDL_Rect){860, BOX_P_Y + 60, 20 * ft_strlen("color : 3"), 20};
	get_text_and_rect("color : 3", sdl, 7, (SDL_Color){0, 0, 0, 255});
	i = -1;
	while (++i < 8)
		SDL_RenderCopy(sdl->ren, sdl->tex[i], NULL, &(sdl->rect[i]));
}

void	get_text_and_rect(char *text, t_sdl *sdl, int idx, SDL_Color color)
{
	sdl->scr = TTF_RenderText_Solid(sdl->font[0], text, color); // as TTF_RenderText_Solid could only be used on SDL_Surface then you have to create the surface first
	sdl->tex[idx] = SDL_CreateTextureFromSurface(sdl->ren, sdl->scr);
}
