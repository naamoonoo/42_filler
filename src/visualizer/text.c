#include "visualizer.h"

void	render_text(t_sdl *sdl, t_f *f)
{
	sdl->rect[0] = (SDL_Rect){50, 20, 400, 100};
	get_text_and_rect("filler", sdl, 0, (SDL_Color){0, 0, 0, 255});
	sdl->rect[1] = (SDL_Rect){680, 40, 20 * ft_strlen(f->p1_name), 30};
	get_text_and_rect(f->p1_name, sdl, 1, f->c_p1);
	sdl->rect[2] = (SDL_Rect){700 + 20 * ft_strlen(f->p1_name),
		40, 20 * ft_numlen(f->s_p1, 10), 30};
	get_text_and_rect(ft_itoa(f->s_p1), sdl, 2, f->c_p1);
	sdl->rect[3] = (SDL_Rect){680, 80, 20 * ft_strlen(f->p2_name), 30};
	get_text_and_rect(f->p2_name, sdl, 3, f->c_p2);
	sdl->rect[4] = (SDL_Rect){700 + 20 * ft_strlen(f->p2_name),
		80, 20 * ft_numlen(f->s_p2, 10), 30};
	get_text_and_rect(ft_itoa(f->s_p2), sdl, 4, f->c_p2);
	sdl->rect[5] = (SDL_Rect){850, 765, 15 * ft_strlen("made by hnam"), 15};
	get_text_and_rect("made by hnam", sdl, 5, (SDL_Color){0, 0, 0, 255});
	sdl->rect[6] = (SDL_Rect){PIECE_P_X, PIECE_P_Y,
		25 * ft_strlen("NEXT PIECE"), 25};
	get_text_and_rect("NEXT PIECE", sdl, 6, (SDL_Color){0, 0, 0, 255});
	render_text2(sdl, f);
}

void	render_text2(t_sdl *sdl, t_f *f)
{
	char	**info;
	int		i;

	i = -1;
	info = ft_strsplit(COMMANDS, '/');
	while (info[++i])
	{
		sdl->rect[i + 7] = (SDL_Rect){
			850, 500 + i * 30, 20 * ft_strlen(info[i]), 20};
		get_text_and_rect(info[i], sdl, i + 7, (SDL_Color){0, 0, 0, 255});
	}
	(void)f;
	free_char_pp(info);
	i = -1;
	while (++i < NUM_OF_INFO)
		SDL_RenderCopy(sdl->ren, sdl->tex[i], NULL, &(sdl->rect[i]));
}

void	get_text_and_rect(char *text, t_sdl *sdl, int idx, SDL_Color color)
{
	sdl->scr = TTF_RenderText_Solid(sdl->font[0], text, color);
	sdl->tex[idx] = SDL_CreateTextureFromSurface(sdl->ren, sdl->scr);
}